#include<stdio.h>
#include<stdlib.h>

typedef struct 
{
    int *array;
    size_t used;
    size_t size;
}Array;

void init_array(Array *a, size_t initial_size){
    a->array = (int*) malloc(initial_size * sizeof(int));
    a->used = 0;
    a->size = initial_size; 
}

void insert_book(Array *a, int pages){
    if (a->used == a->size){
        a->size *= 2;
        a->array = realloc(a->array,a->size * sizeof(int));
    }
    a->array[a->used++] = pages;
}

int get_pages_at_given_position(Array *a, int position){
    return a->array[position];
}

int get_total_books(Array *a){
    return a->used;
}

void free_array(Array *a){
    free(a->array);
    a->array = NULL;
    a->size = a->used = 0;
}


int main(){

    int number_of_shelves;
    printf("Enter the number of shelves in your book shelf :");
    scanf("%d",&number_of_shelves);

    Array *book_shelves;
    book_shelves =(Array*) malloc(number_of_shelves * sizeof(Array));

    //intaialsize the shelf.
    for (size_t i = 0; i < number_of_shelves; i++)
    {
        init_array(&book_shelves[i],number_of_shelves);
    }
    
    int queries;
    printf("\n------->Enter number of query/operation: ");
    scanf("%d",&queries);
    while (queries>0)
    {
        int type_of_query;
        printf("\n------------For Insert book(define by number of pages) in shelf, press 1----------.");
        printf("\n------------Get book from book shelf, press 2.---------------");
        printf("\n------------Get total number of books from a shelf, press 3.-----------\n");
        scanf("%d",&type_of_query);
        
        if (type_of_query == 1){
            int x,y;
            printf("------->In which shelf you want to insert?\n");
            scanf("%d",&x);
            printf("------->insert by input total of pages of your book.\n");
            scanf("%d",&y);
            insert_book(&book_shelves[x],y);
        }
        else if (type_of_query == 2)
        {
            int x,y,pages;
            printf("------->In which shelf your was book placed?\n");
            scanf("%d",&x);
            printf("------->And at what position?\n");
            scanf("%d",&y);
            pages = get_pages_at_given_position(&book_shelves[x],y);
            printf("------->Your book with total number of pages: %d\n",pages);
        }
        else
        {
            int x,books;
            printf("------->total books in which shelf?\n");
            scanf("%d",&x);
            books = get_total_books(&book_shelves[x]);
            printf("------->total number of books in given shelf: %d\n",books);
        }
        queries--;    
    }
    
    // free the each shelf.
    for (size_t i = 0; i < number_of_shelves; i++)
    {
        free_array(&book_shelves[i]);
    }

    //free the book shelves.
    free(book_shelves);
    return 0;
}