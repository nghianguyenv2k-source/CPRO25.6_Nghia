#ifndef BOOK_H
#define BOOK_H

#include <stdio.h>

#define MAX_BOOKS 100       // Maximum number of books in the library

/*-----------------------------------------*/
/*--------Struct of book information-------*/
//-----title, author, ID, availability status-----//
typedef struct 
{
    char title[100];
    char author[100];
    int id;
    int is_available; // 1 if available, 0 if checked out
} Book;
//------Hàm quản lý sach trong thư viện------//


//Thêm sách mới vào thư viện
//tham số: mảng sách, số lượng sách hiện tại, thông tin sách mới
//Thông tin sách mới: tiêu đề, tác giả, ID
void add_book(Book library[], int *book_count, const char *title, const char *author, int id);

//sửa thông tin sách theo ID
//trả về 1 nếu sửa thành công, 0 nếu không tìm thấy sách
int edit_book(Book library[], int book_count, int id, const char *new_title, const char *new_author);

//Xoá sách khỏi thư viện theo ID
//trả về 1 nếu xoá thành công, 0 nếu không tìm thấy sách
int delete_book(Book library[], int *book_count, int id);

//tìm sách theo ID
//trả về chỉ số của sách trong mảng nếu tìm thấy, -1 nếu không tìm thấy
int find_book_by_id(Book library[], int book_count, int id);    

//tìm sách theo tiêu đề
//trả về số lượng sách tìm thấy, kết quả lưu trong mảng results
int find_books_by_title(Book library[], int book_count, const char *title, Book results[]);

//tìm sách theo tác giả
//trả về số lượng sách tìm thấy, kết quả lưu trong mảng results
int find_books_by_author(Book library[], int book_count, const char *author, Book results[]);

//hiển thị danh sách tất cả sách trong thư viện
void display_all_books(Book library[], int book_count);

#endif // BOOK_H