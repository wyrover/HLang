typedef enum{
	AVAILABLE,
	OCCUPIED
}occupation_t;

typedef struct{
	char *value;
	char *name;
	unsigned int scope;
	occupation_t occupation;
}variable_t;

struct map_list{
	char *mapname;
	unsigned int scope;
	struct map_list *next;
};

#define TOTAL_SLOTS 7
#define H_ALPHA 3

typedef unsigned long variable_ptr_t;

/** @brief	Add new variable to storage bin
 *  @param 	new_varname	variable name to be stored
 *  @param	scope		scope number of the variable (defaults 0, file scope)i
 *  @return	Variable storage location in the storage bin
 */
variable_ptr_t vms_add_new_variable(char *new_varname, unsigned int scope);

/** @brief	Finds a valid free location in the storage bin
 *  @param	varname		variable name to use during hashing
 *  @return	closest position in the storage bin which is free corresponding to the given varname (positive offset)
 */
unsigned long vms_find_valid_location(char *varname);


/** @brief	Hashes a given string into an unsigned long
 *  @param	varname		variable name to use during hashing
 *  @return	hashed location in the storage bin
 */
unsigned long vms_calchash(char *varname);


/** @brief	Assign a given storage location with string
 *  @param	var		variable storage location in the storage bin
 *  @param	str		string to save
 */
void vms_assign_to_bin_location(variable_ptr_t var, char *str);

/** @brief	Assig
/** @brief	Finds variable with a given scope in the storage bin
 *  @param	varname		variable name
 *  @param	scope		scope of the variable to be found out
 *  @return	location in storage bin where the variable is stored. If not found, TOTAL_SLOT is returned
 */
variable_ptr_t vms_var_lookup_strict(char *varname, unsigned int scope);
variable_ptr_t vms_var_lookup_leanient(char *varname);
variable_ptr_t vms_add_new_mapelement(char *mapelementname, unsigned int scope);
int vms_init();
void vms_display_variable_table();
int vms_add_new_map(char *new_varname, unsigned int scope);
void vms_display_map_list();
int vms_is_already_declared_variable(char *new_varname, unsigned int scope);
void vms_decommission_scope(unsigned int scope);
int vms_is_mapname_exists(char *mapname, unsigned int scope);
int vms_is_maptype(char *varname);
char *vms_map_part(char *mapelement);
char *vms_getvaluebylocation(variable_ptr_t binlocation);
