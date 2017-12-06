#define INSERT_TO_LIST_HEAD(h, p) \
	do {\
		(p)->bp = (h); \
		(p)->fp = (h)->fp; \
		(h)->fp->bp = (p); \
		(h)->fp = (p);	\
   	} while (0)

#define INSERT_TO_LIST_TAIL(h, p) \
	do {\
		(p)->bp = (h)->bp; \
		(p)->fp = (h)->fp->bp; \
		(h)->bp->fp = (p);	\
		(h)->bp = (p); \
   	} while (0)

#define REMOVE_FROM_LIST(h, p) \
	do {\
		(p)->bp->fp = (p)->fp; \
		(p)->fp->bp = (p)->bp; \
		(h)->bp = (p); \
		(p)->fp = (p)->bp = NULL;	\
   	} while (0)


