package contact; 
// Gets the package name for the class.

import java.util.HashMap; 
// Gets the HashMap class from the java.util package.

import java.util.Map; 
// Gets the Map interface from the java.util package.

public class ContactService { 
	// Declares the ContactService class.
	
    private final Map<String, Contact> contacts = new HashMap<>(); 
    // Declares and initializes a final map to store contacts.

    public void addContact(Contact contact) { 
    	// Method to add a contact to the map.
    	
        // Checks if a contact with the same ID already exists in the map.
        if (contacts.containsKey(contact.getContactId())) {
        	
            throw new IllegalArgumentException("Contact ID already exists"); 
            // Throws an exception if the ID already exists.
        }
        // Adds the contact to the map using the contact ID as the key.
        contacts.put(contact.getContactId(), contact);
    }

    public void deleteContact(String contactId) { 
    	// Method to delete a contact from the map.
    	
        contacts.remove(contactId); 
        // Removes the contact with the given ID from the map.
    }

    public void updateContact(String contactId, String firstName, String lastName, String phone, String address) { 
    	// Method to update a contact's details.
    	
        Contact contact = contacts.get(contactId); 
        // Retrieves the contact with the given ID from the map.
        
        if (contact != null) { 
        	// Checks if the contact exists.
        	
            contact.setFirstName(firstName); 
            // Updates the contact's first name.
            
            contact.setLastName(lastName); 
            // Updates the contact's last name.
            
            contact.setPhone(phone); 
            // Updates the contact's phone number.
            
            contact.setAddress(address); 
            // Updates the contact's address.
        }
    }

    public Contact getContact(String contactId) { 
    	// Method to retrieve a contact from the map.
    	
        return contacts.get(contactId); 
        // Returns the contact with the given ID from the map.
    }
}
