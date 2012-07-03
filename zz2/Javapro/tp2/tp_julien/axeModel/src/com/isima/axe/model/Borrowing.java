package com.isima.axe.model;

import java.util.Date;

/**
 * Classe permettant de g�rer la relation "emprunt" entre Person et Book
 * @author millau - Gentil
 *
 */
public class Borrowing {

	/**
	 * Date d'emprunt
	 */
	private Date borrowingDate;
	/**
	 * Date de retour pr�vue : normalement 3 semaines
	 */
	private Date expectedReturnDate;
	/**
	 * Date de retour r�elle
	 */
	private Date actualReturnDate;
	/**
	 * Le livre concern� par l'emprunt
	 */
	private Book borrowing;
	/**
	 * la personne concern� par l'emprunt
	 */
	private Person borrower;
	
	/**
	 * Contructeur de la classe Borrowing	
	 */
	public Borrowing() {
		setBorrowingDate(new Date());
	}
	
	/**
	 * Methode qui dit si un livre est actuelement emprunt�
	 * @return : true si el livre est deja lou�, false sinon
	 */
	public boolean isInProgress()
	{
		return (actualReturnDate==null);
	}
	
	/**
	 * Methode qui dit si un emprunt est termin�
	 * @return : true si l'emprunt est termin�, false sinon
	 */
	public boolean isCompleted()
	{
		return (!isInProgress());
	}
	
	/**
	 * Methode qui dit si un emprunt est en retard
	 * @return : true si le retour est en retard, false sinon
	 */
	public boolean isLate()
	{
		Date d =new Date();
		return d.after(expectedReturnDate);
	}
	
	
	
	public Date getBorrowingDate() {
		return borrowingDate;
	}
	
	public void setBorrowingDate(Date borrowingDate) {
		this.borrowingDate = borrowingDate;
		if(borrowingDate !=null)
			this.expectedReturnDate = new Date(borrowingDate.getTime()+1814400000);
	}
	public Date getExpectedReturnDate() {
		return expectedReturnDate;
	}
	public Date getActualReturnDate() {
		return actualReturnDate;
	}
	public void setActualReturnDate(Date actualReturnDate) {
		this.actualReturnDate = actualReturnDate;
	}

	/**
	 * Permet d'obtenir le borrowing
	 * @return the borrowing qui est un Book
	 */
	public Book getBorrowing() {
		return borrowing;
	}

	/**
	 * Permet de modifier le borrowing avec celui pass�
	 * en param�tre
	 * @param borrowing le borrowing � modifier
	 */
	public void setBorrowing(Book borrowing) {
		this.borrowing = borrowing;
	}

	/**
	 * Permet d'obtenir le borrower
	 * @return the borrower qui est un Person
	 */
	public Person getBorrower() {
		return borrower;
	}

	/**
	 * Permet de modifier le borrower avec celui pass�
	 * en param�tre
	 * @param borrower le borrower � modifier
	 */
	public void setBorrower(Person borrower) {
		this.borrower = borrower;
	}
	

	/**
	 * Permet de modifier le expectedReturnDate avec celui pass�
	 * en param�tre
	 * @param expectedReturnDate le expectedReturnDate � modifier
	 */
	public void setExpectedReturnDate(Date expectedReturnDate) {
		this.expectedReturnDate = expectedReturnDate;
	}

	
	public String toString() {
		StringBuffer buffer = new StringBuffer();
		buffer.append(String.valueOf(borrowingDate.getTime()));
		buffer.append(";");
		buffer.append(String.valueOf(expectedReturnDate.getTime()));
		buffer.append(";");
		if (actualReturnDate!=null)
			buffer.append(String.valueOf(actualReturnDate.getTime()));
		buffer.append(";");
		buffer.append(borrowing.getId().toString());
		buffer.append(";");
		buffer.append(borrower.getId().toString());
		return buffer.toString();
	}

	
}
