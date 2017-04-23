int exec_begin_execution();
int exec_constructs(struct ast_construct *entry);
struct ast_construct* exec_provide_constructlist_for_function(char *functionname);
int exec_sequential_construct(struct ast_sequentialnode *seq);
int exec_selective_construct(struct ast_selectivenode *seq);
int exec_iterative_construct(struct ast_iterativenode *seq);
int exec_genvardecl(struct ast_sequential_genvardecl *node);
int exec_mapvardecl(struct ast_sequential_mapvardecl *node);
int exec_add_keyval_pairs(char *mapname, struct keyvalpairs *pairs);
