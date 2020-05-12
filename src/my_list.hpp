/* the list */

class element;

// still must know underlying element data type
class my_list
{
public:

    my_list(char *name = NULL);
    my_list(int init_data = 0, char *name = NULL);
    ~my_list();

/*******************
 * LIST OPERATIONS *
 *******************/
    /**
     * @brief Addes an element pointed to by poistion. "-1" means END
     * @param position      Indexed from 0. -1 (DEFAULT) means END
     */
    void add_elem(int data, const int position = -1);

    /**
     * @brief Deletes the element pointed to by poistion
     * @param position      Indexed from 0.
     */
    void delete_elem(const int position);

    /**
     * @brief Append the input list to end of calling object.
     * @param list      The list to be appended to the end.
     */
    void concat(my_list& list);


/******************
 * LIST UTILITIES *
 ******************/

    /**
     * @brief counts the number of elements in list.
     **/
    int  count();
    void print_list();


private:
/************
 * THE GUTS *
 ************/
    char*    list_name;
    element* head;

};

/**
 * @brief The list elements. Future proof: extend to ADTs
 * */
class element
{
public:
    element(int data) : data(data)
    {}

    void write_data(int new_data)
    {data=new_data;}

    int get_data()
    {return data;}

    element* get_next()
    {return next;}

    void new_next(int new_next_data)
    {next = new element(new_next_data);}

    void write_next(element * new_next_ptr)
    {next = new_next_ptr;}    

private:
    int data = 0;
    element* next = NULL;

};

// ADD A TEST PROGRAM:
int test_list();

#if 0
int is_empty(const list *l){ return (NULL == l);}
list* insert_elem(list* l1, list* new_elem, const int position)
list* delete_elem(list* l1, const int position)   
#endif
