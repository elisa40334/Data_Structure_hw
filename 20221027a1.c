/**
 * http://www.mcs.anl.gov/~kazutomo/list/list.h
 *
 * I grub it from linux kernel source code and fix it for user space
 * program. Of course, this is a GPL licensed header file.
 *
 * Here is a recipe to cook list.h for user space program
 *
 * 1. copy list.h from linux/include/list.h
 * 2. remove
 *     - #ifdef __KERNE__ and its #endif
 *     - all #include line
 *     - prefetch() and rcu related functions
 * 3. add macro offsetof() and container_of
 *
 * - kazutomo@mcs.anl.gov
 */

#include <stdio.h>
/**
 * @name from other kernel headers
 */
/*@{*/

/**
 * Get offset of a member
 */
#define offsetof(TYPE, MEMBER) ((size_t) &((TYPE *)0)->MEMBER)

/**
 * Casts a member of a structure out to the containing structure
 * @param ptr        the pointer to the member.
 * @param type       the type of the container struct this is embedded in.
 * @param member     the name of the member within the struct.
 *
 */
#define container_of(ptr, type, member) ((type *)((char *)ptr - offsetof(type, member)))

/*@}*/


/*
 * These are non-NULL pointers that will result in page faults
 * under normal circumstances, used to verify that nobody uses
 * non-initialized list entries.
 */
#define LIST_POISON1  ((void *) 0x00100100)
#define LIST_POISON2  ((void *) 0x00200200)

/**
 * Simple doubly linked list implementation.
 *
 * Some of the internal functions ("__xxx") are useful when
 * manipulating whole lists rather than single entries, as
 * sometimes we already know the next/prev entries and we can
 * generate better code by using them directly rather than
 * using the generic single-entry routines.
 */
struct list_head {
    struct list_head* next, *prev;
};

#define LIST_HEAD_INIT(name) { &(name), &(name) }

#define LIST_HEAD(name) \
    struct list_head name = LIST_HEAD_INIT(name)

#define INIT_LIST_HEAD(ptr) do { \
        (ptr)->next = (ptr); (ptr)->prev = (ptr); \
    } while (0)

/*
 * Insert a new entry between two known consecutive entries.
 *
 * This is only for internal list manipulation where we know
 * the prev/next entries already!
 */
static inline void __list_add(struct list_head* a,struct list_head* prev,struct list_head* next)
{
    next->prev = a;
    a->next = next;
    a->prev = prev;
    prev->next = a;
}

/**
 * list_add - add a new entry
 * @new: new entry to be added
 * @head: list head to add it after
 *
 * Insert a new entry after the specified head.
 * This is good for implementing stacks.
 */
static inline void list_add(struct list_head* a, struct list_head* head)
{
    __list_add(a, head, head->next);
}

/**
 * list_add_tail - add a new entry
 * @new: new entry to be added
 * @head: list head to add it before
 *
 * Insert a new entry before the specified head.
 * This is useful for implementing queues.
 */
static inline void list_add_tail(struct list_head* a, struct list_head* head)
{
    __list_add(a, head->prev, head);
}

/**
 * list_empty - tests whether a list is empty
 * @head: the list to test.
 */
static inline int list_empty(const struct list_head* head)
{
    return head->next == head;
}

/**
 * list_is_singular - tests whether a list has just one entry.
 * @head: the list to test.
 */
static inline int list_is_singular(const struct list_head *head)
{
	return !list_empty(head) && (head->next == head->prev);
}

static inline void __list_cut_position(struct list_head *list,struct list_head *head, struct list_head *entry)
{
	struct list_head *new_first = entry->next;
	list->next = head->next;
	list->next->prev = list;
	list->prev = entry;
	entry->next = list;
	head->next = new_first;
	new_first->prev = head;
}

/**
 * list_cut_position - cut a list into two
 * @list: a new list to add all removed entries
 * @head: a list with entries
 * @entry: an entry within head, could be the head itself
 *	and if so we won't cut the list
 *
 * This helper moves the initial part of @head, up to and
 * including @entry, from @head to @list. You should
 * pass on @entry an element you know is on @head. @list
 * should be an empty list or a list you do not care about
 * losing its data.
 *
 */
static inline void list_cut_position(struct list_head *list,struct list_head *head, struct list_head *entry)
{
	if (list_empty(head))
		return;
	if (list_is_singular(head) &&
		(head->next != entry && head != entry))
		return;
	if (entry == head)
		INIT_LIST_HEAD(list);
	else
		__list_cut_position(list, head, entry);
}

/**
 * list_entry - get the struct for this entry
 * @ptr:    the &struct list_head pointer.
 * @type:   the type of the struct this is embedded in.
 * @member: the name of the list_struct within the struct.
 */
#define list_entry(ptr, type, member) \
    container_of(ptr, type, member)

/**
 * list_for_each    -   iterate over a list
 * @pos:    the &struct list_head to use as a loop counter.
 * @head:   the head for your list.
 */

#define list_for_each(pos, head) \
    for (pos = (head)->next; pos != (head);   \
         pos = pos->next)

/**
 * __list_for_each  -   iterate over a list
 * @pos:    the &struct list_head to use as a loop counter.
 * @head:   the head for your list.
 *
 * This variant differs from list_for_each() in that it's the
 * simplest possible list iteration code, no prefetching is done.
 * Use this for code that knows the list to be very short (empty
 * or 1 entry) most of the time.
 */
#define __list_for_each(pos, head) \
    for (pos = (head)->next; pos != (head); pos = pos->next)

/**
 * list_for_each_entry  -   iterate over list of given type
 * @pos:    the type * to use as a loop counter.
 * @head:   the head for your list.
 * @member: the name of the list_struct within the struct.
 */
#define list_for_each_entry(pos, head, member)              \
    for (pos = list_entry((head)->next, __typeof__(*pos), member);  \
         &pos->member != (head);                    \
         pos = list_entry(pos->member.next, __typeof__(*pos), member))


#include <stdlib.h>

typedef struct {
    int val;
    struct list_head ptr;
} node_t;


void list_print(struct list_head *a){
    node_t *start;
    // list_for_each_entry(start, a, ptr){
    //     printf("%d -> ", start->val);
    // }
    start->ptr = *((a)->next);
    printf("%d",start->ptr.next->val);
    // __list_for_each(start->ptr = *((a)->next), a){
    //     printf("%d -> ", start->val);
    // }
    printf("NULL\n");
    //printf("%d", );
}

int main(void) {
    struct list_head head;
    struct list_head half_of_head;
    struct list_head *cut_point;

    INIT_LIST_HEAD(&head);
    INIT_LIST_HEAD(&half_of_head);

    int n;
    scanf("%d", &n);

    for(int i=0;i<n;i++) {
        node_t* new_node = malloc(sizeof(node_t));
        new_node->val = i;
        list_add_tail(&new_node->ptr, &head);

        if(i+1==n>>1) cut_point = &new_node->ptr;
    }

    puts("Original list: ");
    list_print(&head);
    list_cut_position(&half_of_head, &head, cut_point);
    puts("After cut: ");
    list_print(&half_of_head);
    list_print(&head);

    return 0;
}      