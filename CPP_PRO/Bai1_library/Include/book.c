#include <stdio.h>
#include <string.h>
#include "book.h"

// Thêm sách mới vào thư viện
void add_book(Book library[], int *book_count, const char *title, const char *author, int id)
{
    if(*book_count >= MAX_BOOKS)
    {
         printf("The library was fulled\n");
         return;
    }
     Book new_book;
     new_book.id = id;
     
     int ret;
     ret = snprintf(new_book.title, sizeof(new_book.title), "%s", title);
     if(ret >= sizeof(new_book.title))  printf("The title is too long\n");
     ret = snprintf(new_book.author, sizeof(new_book.author), "%s", author);
     if(ret >= sizeof(new_book.author))  printf("The author's name is too long\n");

     new_book.is_available = 0; // Trạng thái ban đầu = 0 - đang ở trong thư viện
     library[*book_count] = new_book;
     book_count ++;

    printf("The new book was added successfully\n");
}

//Sửa thông tin sách theo id
int edit_book(Book library[], int book_count, int id, const char *new_title, const char *new_author)
{
    int idx = find_book_by_id(library, book_count, id);
    if(idx < 0) return 0;   //không tìm thấy 
    


     if(new_title != NULL)  // Nếu có thay đổi title
     snprintf(library[idx].title, sizeof(library[idx].title), "%s", new_title);

     if(new_author != NULL)  // Nếu có thay đổi author
     snprintf(library[idx].author, sizeof(library[idx].author), "%s", new_title);

     printf("ID of Book whose information was changed: %d\n", id);
     return 1;  //Đã sửa thành công
}

//Xóa sách theo ID
int delete_book(Book library[], int *book_count, int id)
{
    int idx = find_book_by_id(library, book_count, id);
    if(idx < 0) return 0;   //không tìm thấy 

    for(int i =0; i < *book_count -1; i++)
    {
        library[i] = library[i+1];
    }
    book_count --;
    printf("ID of book which was deleted: %d\n", id);
    return 1;
}

//Tìm sách theo ID
int find_book_by_id(Book library[], int book_count, int id)
{
    for(int i = 0; i < book_count; i ++)
    {
        if(library[i].id == id) return i;
        return -1;
    }
}

// ---------------------------
// Hiển thị thông tin một sách
// ---------------------------
void print_book(const Book *book) {
    printf("ID: %d\nTitle: %s\nAuthor: %s\nStatus: %s\n\n",
        book->id, book->title, book->author,
        book->is_available ? "Da muon" : "Co san");
}

// ---------------------------
// Hiển thị tất cả sách
// ---------------------------
void print_all_books(Book library[], int book_count) {
    if (book_count == 0) {
        printf("Thu vien chua co sach.\n");
        return;
    }
    for (int i = 0; i < book_count; i++) {
        print_book(&library[i]);
    }
}