﻿using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace DataAccessLayer.Metier
{
    /// <summary>
    /// Auteur dans la base de donnée
    /// </summary>
    public class AuteurBDD
    {
        /// <summary>
        /// Constructeur
        /// </summary>
        /// <param name="inGUID">GUID</param>
        /// <param name="inNom">Distinction</param>
        /// <param name="inFirstName">Prénom</param>
        /// <param name="inLastName">Nom</param>
        /// <param name="inPhoneNumber">Numéro de téléphone</param>
        /// <param name="inAdress">Adresse</param>
        /// <param name="inZipCode">Code postal</param>
        /// <param name="inCity">Ville</param>
        /// <param name="inState">Etats</param>
        /// <param name="inCountry">Pays</param>
        public AuteurBDD(string inGUID, string inNom, string inFirstName, string inLastName,
                          string inPhoneNumber, string inAdress, string inZipCode, string inCity,
                            string inState, string inCountry)
        {
            GUID = inGUID;
            Nom = inNom;
            FirstName = inFirstName;
            LastName = inLastName;
            PhoneNumber = inPhoneNumber;
            Address = inAdress;
            Zipcode = inZipCode;
            City = inCity;
            State = inState;
            Country = inCountry;
            
        }


        // ------------------------
        // Attribut
        // ------------------------
        string _GUID;

        string _nom;

        string _firstName;

        string _lastName;

        string _phoneNumber;

        string _address;

        string _zipcode;

        string _city;

        string _state;

        string _country;


        // ------------------------
        // Propiétés
        // ------------------------

        public string GUID
        {
            get { return _GUID; }
            set { _GUID = value; }
        }

        public string Nom
        {
          get { return _nom; }
          set { _nom = value; }
        }

        public string FirstName
        {
          get { return _firstName; }
          set { _firstName = value; }
        }
        
        public string LastName
        {
          get { return _lastName; }
          set { _lastName = value; }
        }
        
        public string PhoneNumber
        {
          get { return _phoneNumber; }
          set { _phoneNumber = value; }
        }
        
        public string Address
        {
          get { return _address; }
          set { _address = value; }
        }
        
        public string Zipcode
        {
          get { return _zipcode; }
          set { _zipcode = value; }
        }
        
        public string City
        {
          get { return _city; }
          set { _city = value; }
        }
        
        public string State
        {
          get { return _state; }
          set { _state = value; }
        }

        public string Country
        {
          get { return _country; }
          set { _country = value; }
        }

        

    }
}