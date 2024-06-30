package contact; 
// Gets the package name for the class.

import org.junit.jupiter.api.Test; 
// Gets the Test annotation from the JUnit 5 framework.

import static org.junit.jupiter.api.Assertions.*; 
// Gets all static assertions from the JUnit 5 framework.

public class ContactTest { 
	// Gets the ContactTest class.

    @Test 
    // Shows that this method is a test case.
    
    public void testContact() { 
    	// Test method to verify the creation of a valid contact.
    	
        Contact contact = new Contact("1234567890", "John", "Doe", "1234567890", "123 Main St"); 
        // Creates a new Contact object.
        
        assertEquals("1234567890", contact.getContactId()); 
        // Makes sure that the contact ID is correctly set.
        
        assertEquals("John", contact.getFirstName()); 
        // Makes sure that the first name is correctly set.
        
        assertEquals("Doe", contact.getLastName()); 
        // Makes sure that the last name is correctly set.
        
        assertEquals("1234567890", contact.getPhone()); 
        // Makes sure that the phone number is correctly set.
        
        assertEquals("123 Main St", contact.getAddress()); 
        // Makes sure that the address is correctly set.
    }

    @Test 
    // Shows that this method is a test case.
    
    public void testInvalidContactId() { 
    	// Test method to verify handling of invalid contact IDs.
    	
        // Makes sure that creating a contact with a null ID throws an IllegalArgumentException.
        assertThrows(IllegalArgumentException.class, () -> new Contact(null, "John", "Doe", "1234567890", "123 Main St"));
        
        // Makes sure that creating a contact with an ID longer than 10 characters throws an IllegalArgumentException.
        assertThrows(IllegalArgumentException.class, () -> new Contact("12345678901", "John", "Doe", "1234567890", "123 Main St"));
    }

    @Test 
    // Shows that this method is a test case.
    
    public void testInvalidFirstName() { 
    	// Test method to verify handling of invalid first names.
    	
        // Makes sure that creating a contact with a null first name throws an IllegalArgumentException.
        assertThrows(IllegalArgumentException.class, () -> new Contact("1234567890", null, "Doe", "1234567890", "123 Main St"));
        
        // Makes sure that creating a contact with a first name longer than 10 characters throws an IllegalArgumentException.
        assertThrows(IllegalArgumentException.class, () -> new Contact("1234567890", "John1234567890", "Doe", "1234567890", "123 Main St"));
    }

    @Test 
    // Shows that this method is a test case.
    
    public void testInvalidLastName() { 
    	// Test method to verify handling of invalid last names.
    	
        // Makes sure that creating a contact with a null last name throws an IllegalArgumentException.
        assertThrows(IllegalArgumentException.class, () -> new Contact("1234567890", "John", null, "1234567890", "123 Main St"));
        
        // Makes sure that creating a contact with a last name longer than 10 characters throws an IllegalArgumentException.
        assertThrows(IllegalArgumentException.class, () -> new Contact("1234567890", "John", "Doe1234567890", "1234567890", "123 Main St"));
    }

    @Test 
    // Shows that this method is a test case.
    
    public void testInvalidPhone() { 
    	// Test method to verify handling of invalid phone numbers.
    	
        // Makes sure that creating a contact with a null phone number throws an IllegalArgumentException.
        assertThrows(IllegalArgumentException.class, () -> new Contact("1234567890", "John", "Doe", null, "123 Main St"));
        
        // Makes sure that creating a contact with a phone number shorter than 10 characters throws an IllegalArgumentException.
        assertThrows(IllegalArgumentException.class, () -> new Contact("1234567890", "John", "Doe", "123456789", "123 Main St"));
        
        // Makes sure that creating a contact with a phone number longer than 10 characters throws an IllegalArgumentException.
        assertThrows(IllegalArgumentException.class, () -> new Contact("1234567890", "John", "Doe", "12345678901", "123 Main St"));
    }

    @Test 
    // Shows that this method is a test case.
    
    public void testInvalidAddress() { 
    	// Test method to verify handling of invalid addresses.
    	
        // Makes sure that creating a contact with a null address throws an IllegalArgumentException.
        assertThrows(IllegalArgumentException.class, () -> new Contact("1234567890", "John", "Doe", "1234567890", null));
        
        // Makes sure that creating a contact with an address longer than 30 characters throws an IllegalArgumentException.
        assertThrows(IllegalArgumentException.class, () -> new Contact("1234567890", "John", "Doe", "1234567890", "123 Main St 123 Main St 123 Main St 123 Main St"));
    }
}
