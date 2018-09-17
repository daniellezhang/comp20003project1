#define MAX_STRING 128
struct athlete_t;
struct athlete_t *insert(struct athlete_t *parent, struct athlete_t *new);
struct athlete_t *makedict(FILE *datafile);
void free_tree(struct athlete_t *head);
int search(struct athlete_t *head, char key[MAX_STRING+1],
  FILE *outputfile, int found);
