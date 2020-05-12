/* the list */

#include <stdio.h>
#include <stdlib.h>

#include "my_list.hpp"

my_list::my_list(char *name)
{
    head = NULL;
}

my_list::my_list(int init_data, char *name)
{      
    head = new element(init_data);
}

my_list::~my_list()
{}

/*******************
 * LIST OPERATIONS *
 *******************/

void my_list::add_elem(int data, const int position)
{
    element* elem_ptr  = head;
    int      position_track = 0;

    if (0 == position)
    {
        head = new element(data);
        head->write_next(elem_ptr);
    }
    else
    {
        while(NULL != elem_ptr)
        {
            if ( ((position - 1) == position_track) ||
                 (-1 == position) )
            {
                if (NULL == elem_ptr->get_next())
                {
                   elem_ptr->new_next(data);
                   break;
                }

                element* tmp = elem_ptr->get_next();
                elem_ptr->new_next(data);
                elem_ptr = elem_ptr->get_next();
                elem_ptr->write_next(tmp);
                break;
            }
            elem_ptr = elem_ptr->get_next();
            position_track++;
        }
    }
    return;
}

void my_list::delete_elem(const int position)
{
    //tranverse to position
    element* elem_ptr  = head;
    int      position_track = 0;

    // zero position
    if (0 == position)
    {
        element* to_be_deleted = head;
        head = head->get_next();
        delete to_be_deleted;
    }
    else
    {
        while(NULL != elem_ptr->get_next())
        {
            if ((position - 1) == position_track)
            {
                element* to_be_updated = elem_ptr;
                element* to_be_deleted = elem_ptr->get_next();

                elem_ptr = elem_ptr->get_next();
                to_be_updated->write_next(elem_ptr->get_next());

                delete to_be_deleted;
                position_track++; //for ERROR message condition
                break;
            }
            elem_ptr = elem_ptr->get_next();
            position_track++;
        }
        if(position_track < position)
        {
            printf("\t---ERROR: delete_elem() position not found. List too short?\n");
        }
    }
    return;
}

void my_list::concat(my_list &list) //put in l1
{
    element* elem_ptr  = head;

    while(NULL != elem_ptr)
    {
        if(NULL == elem_ptr->get_next())
        {
            break;
        }
        else
        {
            elem_ptr = elem_ptr->get_next();
        }
    }
    elem_ptr->write_next(list.head);
}

/******************
 * LIST UTILITIES *
 ******************/
int my_list::count()
{
    element* elem_ptr  = head;
    int      num_elems = 0;

    while (NULL != elem_ptr)
    {
        num_elems++;
        elem_ptr = elem_ptr->get_next();
    }

    return(num_elems);
}

void my_list::print_list()
{
    int         elem_counter = 0;
    element*    elem_ptr     = this->head;

    while(NULL != elem_ptr)
    {
        printf("elem[%d].data: %d\n",elem_counter, elem_ptr->get_data());
        elem_counter++;
        elem_ptr = elem_ptr->get_next();
    }
    return;
}

// TEST PROGRAM INCLUDED
int test_list()
{

    printf("\n==TEST== CREAT TWO LISTS: === \n");
    my_list l1(1);
    l1.print_list();
    my_list l2(-1);
    l2.print_list();
    printf("==TEST END === \n\n");


    printf("==TEST== ADD ELEMENT TO END LIST 1: === \n");
    l1.add_elem(2,-1);
    l1.print_list();
    printf("==TEST END === \n\n");


    printf("==TEST== ADD ELEMENT TO FRONT LIST 2: === \n");
    l2.add_elem(-2, 0);
    l2.print_list();
    printf("==TEST END === \n\n");


    printf("==TEST== COUNT ELEMENTS BOTH LISTS: === \n");
    int num_el_l1 = l1.count();
    int num_el_l2 = l2.count();
    printf("LIST 1: %d ELEMENTS\n",num_el_l1);
    printf("LIST 2: %d ELEMENTS\n",num_el_l2);
    printf("==TEST END === \n\n");


    printf("==TEST== ADD TO FRONT L1 AND CONCAT WITH L2: === \n");
    l1.add_elem(0,0);
    printf("L1 WITH NEW HEAD:\n");
    l1.print_list();
    printf("L2 TO BE CONCATENATED:\n");
    l2.print_list();
    printf("CONCAT: L1+L2\n");
    l1.concat(l2);
    l1.print_list();
    printf("==TEST END === \n\n");


    printf("==TEST== ADD ELEM POSITION 3 IN L1: === \n");
    printf("LIST L1 STATE:  \n");
    l1.print_list();
    printf("--SUB TEST 1: ADD ELEM: 100 pos 0: \n");
    l1.add_elem(100, 0);
    l1.print_list();
    printf("--SUB TEST 2: ADD ELEM: -100 pos END: \n");
    l1.add_elem(-100, 6);
    l1.print_list();
    printf("--SUB TEST 3: ADD ELEM: pos 300 DATA: 3\n");
    l1.add_elem(300, 3);
    l1.print_list();
    printf("==TEST END === \n\n");


    printf("==TEST== DELETE ELEM POSITION 3 IN L1: === \n");
    printf("LIST L1 STATE:  \n");
    l1.print_list();
    printf("DELETE ELEM: OUT OF BOUNDS. ERROR MESSAGE ONLY: \n");
    int out_of_bounds = l1.count(); // no add as delete indexes from 0
    l1.delete_elem(out_of_bounds);
    l1.print_list();
    printf("DELETE ELEM: 300 pos 3 \n");
    l1.delete_elem(3);
    l1.print_list();
    printf("==TEST END === \n\n");


    return(0);
}
