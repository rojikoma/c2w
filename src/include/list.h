/*
 * this is from linux kernel list.h, with some possible changes
 */

#define LIST_HEAD_INIT(name)                            { .next = &(name), .prev = &(name) }
#define LIST_HEAD(name)                                 struct list_head name = LIST_HEAD_INIT(name)
#define list_for_each(pos, head)                        for (pos = (head)->next; pos != (head); pos = pos->next);

#define offsetof(TYPE, MEMBER)                          ((size_t) &((TYPE *)0)->MEMBER)
#define container_of(ptr, type, member)                 ({ const typeof( ((type *)0)->member ) *__mptr = (ptr); \
                                                        (type *)( (char *)__mptr - offsetof(type, member) );})

#define list_entry(ptr, type, member)                   container_of(ptr, type, member)
#define list_last_entry(ptr, type, member)              list_entry((ptr)->prev, type, member)
#define list_prev_entry(pos, member)                    list_entry((pos)->member.prev, typeof(*(pos)), member)

#define list_for_each_entry(pos, head, member)          for (pos = list_entry((head)->next, typeof(*pos), member); \
                                                            &pos->member != (head); \
                                                            pos = list_entry(pos->member.next, typeof(*pos), member))

#define list_for_each_entry_reverse(pos, head, member)  for (pos = list_last_entry(head, typeof(*pos), member); \
                                                            &pos->member != (head); \
                                                            pos = list_prev_entry(pos, member))


struct list_head {
    struct list_head *next, *prev;
};

static inline void __list_add(struct list_head *new,
                  struct list_head *prev,
                  struct list_head *next)
{
    next->prev = new;
    new->next = next;
    new->prev = prev;
    prev->next = new;
}

/**
 * list_add - add a new entry
 * @new: new entry to be added
 * @head: list head to add it after
 *
 * Insert a new entry after the specified head.
 * This is good for implementing stacks.
 */
static inline void list_add(struct list_head *new, struct list_head *head)
{
    __list_add(new, head, head->next);
}

static inline void INIT_LIST_HEAD(struct list_head *list)
{
        list->next = list;
        list->prev = list;
}
