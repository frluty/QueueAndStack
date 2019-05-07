#include <stdio.h>
#include <stdlib.h>

 /*les files */
 /*la structure de la file FIFO*/
	typedef struct element{
		char data[255];
		struct element *next;
	}element;

typedef struct file
{
    struct element* begin;
    struct element* end;
    int nb_element;
}file;
/* ajouter un element dans la file*/

void file_enqueue(file *p_file, struct element* el)
	{
		/*
        struct element *new_el=malloc(sizeof(struct element*));
        new_el=el;
        new_el->next=NULL;//*/
		if(p_file->nb_element==0)
		{
            p_file->begin=el;
            p_file->end=el;
            p_file->nb_element=1;
		}
		else
		{
            p_file->end->next=el;
            p_file->end=el;
            p_file->nb_element++;
		}

	}

	/* retirer un element de la file*/
	void file_del(file * p_file)
	{

		if(p_file->nb_element==1)
		{
            free(p_file->begin);
            p_file->begin=NULL;
            p_file->end=NULL;
            p_file->nb_element=0;
		}
		else
		{
            element *tmp=p_file->begin->next;
            free(p_file->begin);
            p_file->begin=tmp;
            p_file->nb_element--;

        }
	}
	/* vidage de la file*/
	void file_clear(file *p_file)
	{
		while(p_file!=NULL)
            file_del(p_file);
	}
	/*le premier de la file*/
	element * file_first(file *p_file)
	{
            return p_file->begin;
	}
	/*pour afficher la file*/
	void print_file(file *p_file)
	{
		element *tmp=p_file->begin;
		while(tmp!=NULL)
		{
			printf("%s  ",tmp->data);
			tmp=tmp->next;
		}
	}
 int main(){

    file *p_file = malloc(sizeof *p_file);
	p_file->nb_element =0;
	int j=0;
	printf("\n---------Welcome To Fifo-----------------\n");
	if( p_file !=NULL)
	{
		///*
		for(j=0;j<=10;j++)
		{
			struct element *ele=malloc(sizeof (struct element));
			sprintf(ele->data,"%d",j);
			file_enqueue(p_file,ele);
		}
		printf("Nb element %d\n",p_file->nb_element);
		print_file(p_file);
		printf("\n%s\n",file_first(p_file)->data);
		file_del(p_file);
		print_file(p_file);//*/
	}
	else
	{
		printf("the Queue is empty :)");
	}
	
    return 0;
}
