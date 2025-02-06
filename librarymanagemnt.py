import datetime
import asyncio
from abc import ABC ,  abstractmethod

class SmallLibrary:
    def __init__(self):
        self.book = {}
        self.registry = {}

    def addBook(self, BOOK: Book):
        book[BOOK.book_id]


class Book:
    def __init__(self, book_id, title, author, total_copies):
        self.book_id = book_id
        self.title = title
        self.author = author
        self.total_copies = total_copies
        self.available_copies = total_copies

    def update_copies(self, count):
        self.available_copies += count

    def display_info(self):
        return f"{self.title} by {self.author} - {self.available_copies}/{self.total_copies} available"


class Member:
    def __init__(self, member_id, name):
        self.member_id = member_id
        self.name = name
        self.borrowed_books = {}

    def borrow_book(self, book):
        if len(self.borrowed_books) < 3:  # Limit to 3 books
            self.borrowed_books[book.book_id] = datetime.date.today()
            book.update_copies(-1)
        else:
            print("Borrow limit reached.")

    def return_book(self, book):
        if book.book_id in self.borrowed_books:
            self.borrowed_books.pop(book.book_id)
            book.update_copies(1)
        else:
            print("Book not borrowed.")


class Library:
    def __init__(self):
        self.books = {}
        self.members = {}

    def add_book(self, book):
        self.books[book.book_id] = book

    def remove_book(self, book_id):
        if book_id in self.books:
            self.books.pop(book_id)

    def lend_book(self, member_id, book_id):
        if member_id in self.members and book_id in self.books:
            member = self.members[member_id]
            book = self.books[book_id]
            if book.available_copies > 0:
                member.borrow_book(book)
            else:
                print("Book is not available.")
        else:
            print("Invalid member or book ID.")

    def return_book(self, member_id, book_id):
        if member_id in self.members and book_id in self.books:
            member = self.members[member_id]
            book = self.books[book_id]
            member.return_book(book)


library = Library()

book1 = Book(1, "1984", "George Orwell", 5)
book2 = Book(2, "To Kill a Mockingbird", "Harper Lee", 3)
library.add_book(book1)
library.add_book(book2)


member1 = Member(1, "Alice")
library.members[1] = member1

library.lend_book(1, 1)
print(book1.display_info())

library.remove_book()

library.return_book(1, 1)
print(book1.display_info())


class Solution(object):
    def subtractProductAndSum(self, n):
        """
        :type n: int
        :rtype: int
        """
        sum = 0
        product = 1

        while n>0:
            digit = n % 10
            sum+= digit
            product *= digit
            n = n//10
        return product-sum