# Hotel-Management-System
C++ Console-based Hotel Management System. Built with structured programming, this system includes roles for managers and receptionists, featuring worker/resident management, cost calculations, room assignment, and income reporting. Developed collaboratively by a 4-member team as a university project.

## Key Features
- **Role-Based Access**
  - Manager: Worker management, financial reports
  - Receptionist: Resident operations, room assignments
- **Core Modules**
  - Resident CRUD operations (Add/Edit/Delete)
  - Room status tracking (Available/Occupied)
  - Worker management with salary records
  - Automated cost calculation system
- **Financial Tools**
  - Weekly/Monthly income reports
  - Maintenance cost analysis
  - Profit/loss statements

## Technical Specifications
- **Language**: C++17
- **Data Structures**: Custom structs with array storage
- **Key Algorithms**:
  - Boarding cost multipliers (FB/HB/BB)
  - Duration-based pricing
  - Automated room assignment logic

Login Credentials
Role	Username	Password
Manager	gerges	gerges1919
Receptionist	hamada	hamada2121

Team Contributions
Member	Key Responsibilities
Ahmed Ashraf	Worker CRUD, Room monitoring
Gerges Hany	Authentication system, Core architecture
Ziad Elnoby	Resident management system
Omar Ehab	Financial reporting modules


## Compilation & Usage
```bash
# Compile with:
g++ -std=c++17 Hotel_Management_System.cpp -o hotel_app

# Run with:
./hotel_app
