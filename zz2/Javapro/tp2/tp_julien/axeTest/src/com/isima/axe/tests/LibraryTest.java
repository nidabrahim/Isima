package com.isima.axe.tests;

import java.util.UUID;

import com.isima.axe.model.Book;
import com.isima.axe.model.Library;

import junit.framework.TestCase;

public class LibraryTest extends TestCase {
	
	/**
	 * Permet de tester l'ajout d'un livre
	 */
	public static void testAddBook()
	{
		Book b = new Book();
		b.setAuthor("Remi");
		b.setId(UUID.randomUUID());
		b.setTitle("test");
		Library l = new Library();
		
		assertTrue("addBook methode false",l.addBook(b));
		assertTrue("la liste ne contient pas le livre ajout�",l.getBooks().containsKey(b.getId()));
		assertFalse("addbook methode true alors que l'objet est null", l.addBook(null));
		assertTrue("La librairie n'a pas �t� ajout� au livre",b.getLibrary()==l);
		l.addBook(b);
		assertTrue("le meme livre est ajout� 2 fois",l.getBooks().size()==1);
	}

}
