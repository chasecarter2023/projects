package contact; 
// Gets the package name for the class.

public class Contact { 
	// Gets the Contact class.
	
    private final String contactId; 
    // Gets a final instance variable for the contact ID.
    
    private String firstName; 
    // Gets an instance variable for the first name.
    
    private String lastName; 
    // Gets an instance variable for the last name.
    
    private String phone; 
    // Declares an instance variable for the phone number.
    
    private String address; 
    // Declares an instance variable for the address.

    public Contact(String contactId, String firstName, String lastName, String phone, String address) { 
    	// Constructor for the Contact class.
    	
        // Checks the contact ID (must not be null and must be 10 characters or less).
        if (contactId == null || contactId.length() > 10) throw new IllegalArgumentException("Invalid contact ID");
       
        // Checks the first name (must not be null and must be 10 characters or less).
        if (firstName == null || firstName.length() > 10) throw new IllegalArgumentException("Invalid first name");
        
        // Checks the last name (must not be null and must be 10 characters or less).
        if (lastName == null || lastName.length() > 10) throw new IllegalArgumentException("Invalid last name");
        
        // Checks the phone number (must not be null and must be exactly 10 characters).
        if (phone == null || phone.length() != 10) throw new IllegalArgumentException("Invalid phone number");
        
        // Checks the address (must not be null and must be 30 characters or less).
        if (address == null || address.length() > 30) throw new IllegalArgumentException("Invalid address");

        this.contactId = contactId; 
        // Assigns the validated contact ID to the instance variable.
        
        this.firstName = firstName; 
        // Assigns the validated first name to the instance variable.
        
        this.lastName = lastName; 
        // Assigns the validated last name to the instance variable.
        
        this.phone = phone; 
        // Assigns the validated phone number to the instance variable.
        
        this.address = address; 
        // Assigns the validated address to the instance variable.
    }

    public String getContactId() { 
    	// Getter method for contactId.
    	
        return contactId; 
        // Returns the contact ID.
    }

    public String getFirstName() { 
    	// Getter method for firstName.
    	
        return firstName; 
        // Returns the first name.
    }

    public void setFirstName(String firstName) { 
    	// Setter method for firstName.
    	
        // Checks the first name (must not be null and must be 10 characters or less).
        if (firstName == null || firstName.length() > 10) throw new IllegalArgumentException("Invalid first name");
        
        this.firstName = firstName; 
        // Assigns the validated first name to the instance variable.        
    }

    public String getLastName() { 
    	// Getter method for lastName.
    	
        return lastName; 
        // Returns the last name.
    }

    public void setLastName(String lastName) { 
    	// Setter method for lastName.
    	
        // Checks the last name (must not be null and must be 10 characters or less).
        if (lastName == null || lastName.length() > 10) throw new IllegalArgumentException("Invalid last name");
        
        this.lastName = lastName; 
        // Assigns the validated last name to the instance variable.
    }

    public String getPhone() { 
    	// Getter method for phone.
    	
        return phone; 
        // Returns the phone number.
    }

    public void setPhone(String phone) { 
    	// Setter method for phone.
    	
        // Checks the phone number (must not be null and must be exactly 10 characters).
        if (phone == null || phone.length() != 10) throw new IllegalArgumentException("Invalid phone number");
        
        this.phone = phone; 
        // Assigns the validated phone number to the instance variable.
    }

    public String getAddress() { 
    	// Getter method for address.
    	
        return address; 
        // Returns the address.
    }

    public void setAddress(String address) { 
    	// Setter method for address.
    	
        // Checks the address (must not be null and must be 30 characters or less).
        if (address == null || address.length() > 30) throw new IllegalArgumentException("Invalid address");
        
        this.address = address; 
        // Assigns the validated address to the instance variable.
    }
}
