#include <stdio.h>
#include <string.h>
#include "book.h"

int main() {
    Book library[MAX_BOOKS];   // Mảng chứa danh sách sách
    int book_count = 0;        // Biến đếm số lượng sách hiện có

    int choice;
    do {
        printf("=====================================\n");
        printf("     CHUONG TRINH QUAN LY THU VIEN\n");
        printf("=====================================\n");
        printf("1. Them sach moi\n");
        printf("2. Sua thong tin sach\n");
        printf("3. Xoa sach\n");
        printf("4. Hien thi tat ca sach\n");
        printf("5. Tim sach theo ID\n");
        printf("6. Tim sach theo ten\n");
        printf("0. Thoat\n");
        printf("Chon chuc nang: ");
        scanf("%d", &choice);
        getchar(); // đọc bỏ ký tự newline sau scanf

        if (choice == 1) {
            int id;
            char title[100], author[100];
            printf("Nhap ID: "); scanf("%d", &id); getchar();
            printf("Nhap ten sach: "); fgets(title, sizeof(title), stdin);
            printf("Nhap tac gia: "); fgets(author, sizeof(author), stdin);

            // loại bỏ ký tự '\n' cuối chuỗi (do fgets)
            title[strcspn(title, "\n")] = 0;
            author[strcspn(author, "\n")] = 0;

            add_book(library, &book_count, title, author, id);
        }

        else if (choice == 2) {
            int id;
            char title[100], author[100];
            printf("Nhap ID sach can sua: "); scanf("%d", &id); getchar();
            printf("Nhap ten moi (bo trong neu giu nguyen): ");
            fgets(title, sizeof(title), stdin);
            printf("Nhap tac gia moi (bo trong neu giu nguyen): ");
            fgets(author, sizeof(author), stdin);

            title[strcspn(title, "\n")] = 0;
            author[strcspn(author, "\n")] = 0;

            // Nếu người dùng để trống, truyền NULL
            const char *new_title = strlen(title) ? title : NULL;
            const char *new_author = strlen(author) ? author : NULL;

            if (!edit_book(library, book_count, id, new_title, new_author))
                printf("Khong tim thay sach co ID %d\n", id);
        }

        else if (choice == 3) {
            int id;
            printf("Nhap ID sach can xoa: ");
            scanf("%d", &id);
            if (!delete_book(library, &book_count, id))
                printf("Khong tim thay sach co ID %d\n", id);
        }

        else if (choice == 4) {
            print_all_books(library, book_count);
        }

        else if (choice == 5) {
            int id;
            printf("Nhap ID sach: ");
            scanf("%d", &id);
            int idx = find_book_by_id(library, book_count, id);
            if (idx != -1)
                print_book(&library[idx]);
            else
                printf("Khong tim thay sach co ID %d\n", id);
        }

        else if (choice == 6) {
            char keyword[100];
            int results[MAX_BOOKS];
            printf("Nhap tu khoa ten sach: ");
            getchar(); // clear buffer
            fgets(keyword, sizeof(keyword), stdin);
            keyword[strcspn(keyword, "\n")] = 0;

            int found = find_books_by_title(library, book_count, keyword, results);
            if (found == 0)
                printf("Khong tim thay sach nao co tu khoa '%s'\n", keyword);
            else {
                printf("Tim thay %d sach:\n", found);
                for (int i = 0; i < found; i++) {
                    print_book(&library[results[i]]);
                }
            }
        }

    } while (choice != 0);

    printf("Thoat chuong trinh.\n");
    return 0;
}



