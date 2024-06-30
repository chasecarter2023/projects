package contact; 
// Makes the package name for the class.

import org.junit.jupiter.api.BeforeEach; 
// Makes the BeforeEach annotation from the JUnit 5 framework.

import org.junit.jupiter.api.Test; 
// Makes the Test annotation from the JUnit 5 framework.

import static org.junit.jupiter.api.Assertions.*; 
// Makes all static assertions from the JUnit 5 framework.

public class ContactServiceTest { 
	// Makes the ContactServiceTest class.
	
    private ContactService contactService; 
    // Makes an instance variable for ContactService.

    @BeforeEach 
    // Shows that this method should be run before each test.
    
    public void setUp() { 
    	// To set up the test environment.
    	
        contactService = new ContactService(); 
        // Makes sure the contactService instance.
    }

    @Test 
    // Makes sure that this method is a test case.
    
    public void testAddContact() { 
    	// Test method to verify adding a contact.
    	
        Contact contact = new Contact("1234567890", "John", "Doe", "1234567890", "123 Main St"); 
        // Makes a new Contact object
        
        contactService.addContact(contact); 
        // Adds the contact to the service.
        
        assertEquals(contact, contactService.getContact("1234567890")); 
        // Makes sure that the added contact can be retrieved correctly.
    }

    @Test 
    // Shows that this method is a test case.
    
    public void testAddContactDuplicateId() { 
    	// Test method to verify handling of duplicate contact IDs.
    	
        Contact contact1 = new Contact("1234567890", "John", "Doe", "1234567890", "123 Main St"); 
        // Makes the first Contact object.
        
        Contact contact2 = new Contact("1234567890", "Jane", "Doe", "0987654321", "456 Elm St"); 
        // Makes the second Contact object with the same ID.
        
        contactService.addContact(contact1); 
        // Adds the first contact to the service.
        
        // Makes sure that adding a second contact with the same ID throws an IllegalArgumentException.
        assertThrows(IllegalArgumentException.class, () -> contactService.addContact(contact2));
    }

    @Test 
    // Shows that this method is a test case.
    
    public void testDeleteContact() { 
    	// Test method to verify deleting a contact.
    	
        Contact contact = new Contact("1234567890", "John", "Doe", "1234567890", "123 Main St"); 
        // Makes a new Contact object.
        
        contactService.addContact(contact); 
        // Adds the contact to the service.
        
        contactService.deleteContact("1234567890"); 
        // Removes the contact from the service.
        
        assertNull(contactService.getContact("1234567890")); 
        // Makes sure that the contact has been removed and cannot be retrieved.
    }

    @Test 
    // Shows that this method is a test case.
    
    public void testUpdateContact() { 
    	// Test method to verify updating a contact's details.
    	
        Contact contact = new Contact("1234567890", "John", "Doe", "1234567890", "123 Main St"); 
        // Makes a new Contact object.
        
        contactService.addContact(contact); 
        // Adds the contact to the service.
        
        // Updates the contact's details.
        contactService.updateContact("1234567890", "Jane", "Smith", "0987654321", "456 Elm St");
        
        Contact updatedContact = contactService.getContact("1234567890"); 
        // Gets the updated contact from the service.
        
        assertEquals("Jane", updatedContact.getFirstName()); 
        // Makes sure that the first name has been updated.
        
        assertEquals("Smith", updatedContact.getLastName()); 
        // Makes sure that the last name has been updated.
        
        assertEquals("0987654321", updatedContact.getPhone()); 
        // Makes sure that the phone number has been updated.
        
        assertEquals("456 Elm St", updatedContact.getAddress()); 
        // Makes sure that the address has been updated.
    }
}
