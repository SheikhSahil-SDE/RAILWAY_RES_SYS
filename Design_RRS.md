# Design for Railway Reservation System (RRS)

## 1. Data Flow Diagrams (DFDs)

### 1.1 Context Level DFD
- **External Entities**:
  - Passenger: Interacts with the system to book, modify, or cancel tickets.
  - Admin: Manages train schedules and monitors bookings.
  - Payment Gateway: Processes payments securely.
- **Processes**:
  - Ticket Booking
  - Train Management
  - Payment Processing
- **Data Stores**:
  - User Database
  - Train Database
  - Reservation Database

### 1.2 Level 1 DFD
#### Processes:
1. **User Management**:
   - Input: User credentials
   - Output: User profile, authentication status
   - Data Store: User Database

2. **Train Management**:
   - Input: Train details (schedule, route, availability)
   - Output: Updated train information
   - Data Store: Train Database

3. **Reservation System**:
   - Input: Train search criteria, booking details
   - Output: Booking confirmation, PNR
   - Data Store: Reservation Database

4. **Payment Processing**:
   - Input: Payment details
   - Output: Payment confirmation
   - External Entity: Payment Gateway

## 2. Entity-Relationship Diagram (ERD)

### Entities and Relationships:
1. **Passenger**:
   - Attributes: PassengerID (PK), Name, Email, Phone, Address
   - Relationships: Books tickets (1:M with Reservation)

2. **Train**:
   - Attributes: TrainID (PK), TrainName, Source, Destination, Schedule, Capacity
   - Relationships: Has reservations (1:M with Reservation)

3. **Reservation**:
   - Attributes: ReservationID (PK), PNR, Date, SeatNumber, Status
   - Relationships: Linked to Passenger (M:1) and Train (M:1)

4. **Admin**:
   - Attributes: AdminID (PK), Name, Email, Role
   - Relationships: Manages trains (1:M with Train)

5. **Payment**:
   - Attributes: PaymentID (PK), Amount, Date, Status
   - Relationships: Linked to Reservation (1:1)

### ERD Description:
- A **Passenger** can book multiple **Reservations**, but each **Reservation** is linked to one **Passenger**.
- A **Train** can have multiple **Reservations**, but each **Reservation** is linked to one **Train**.
- Each **Reservation** has one **Payment**, and each **Payment** is linked to one **Reservation**.
- An **Admin** manages multiple **Trains**.

## 3. Data Dictionary

### 3.1 Passenger Table
| Attribute     | Data Type   | Description                     |
|---------------|-------------|---------------------------------|
| PassengerID   | INT (PK)    | Unique identifier for passenger |
| Name          | VARCHAR(50) | Passenger's full name           |
| Email         | VARCHAR(50) | Passenger's email address       |
| Phone         | VARCHAR(15) | Passenger's phone number        |
| Address       | TEXT        | Passenger's address             |

### 3.2 Train Table
| Attribute     | Data Type   | Description                     |
|---------------|-------------|---------------------------------|
| TrainID       | INT (PK)    | Unique identifier for train     |
| TrainName     | VARCHAR(50) | Name of the train               |
| Source        | VARCHAR(50) | Starting station                |
| Destination   | VARCHAR(50) | Ending station                  |
| Schedule      | DATETIME    | Train schedule                  |
| Capacity      | INT         | Total seat capacity             |

### 3.3 Reservation Table
| Attribute     | Data Type   | Description                     |
|---------------|-------------|---------------------------------|
| ReservationID | INT (PK)    | Unique identifier for booking   |
| PNR           | VARCHAR(20) | Passenger Name Record           |
| Date          | DATETIME    | Date of reservation             |
| SeatNumber    | INT         | Seat number allocated           |
| Status        | VARCHAR(20) | Booking status (e.g., Confirmed, Cancelled) |

### 3.4 Payment Table
| Attribute     | Data Type   | Description                     |
|---------------|-------------|---------------------------------|
| PaymentID     | INT (PK)    | Unique identifier for payment   |
| Amount        | DECIMAL(10,2)| Payment amount                 |
| Date          | DATETIME    | Payment date                   |
| Status        | VARCHAR(20) | Payment status (e.g., Success, Failed) |

### 3.5 Admin Table
| Attribute     | Data Type   | Description                     |
|---------------|-------------|---------------------------------|
| AdminID       | INT (PK)    | Unique identifier for admin     |
| Name          | VARCHAR(50) | Admin's full name               |
| Email         | VARCHAR(50) | Admin's email address           |
| Role          | VARCHAR(20) | Admin's role (e.g., Manager)    |

## 4. Modular Design

To ensure scalability, maintainability, and ease of development, the Railway Reservation System (RRS) is divided into the following modules:

### 4.1 User Management Module
- **Responsibilities**:
  - User registration, login, and profile management.
  - Role-based access control for passengers and administrators.
- **Key Components**:
  - User authentication service.
  - User database.

### 4.2 Train Management Module
- **Responsibilities**:
  - Adding, updating, and deleting train schedules.
  - Managing train routes and seat availability.
- **Key Components**:
  - Train management service.
  - Train database.

### 4.3 Reservation Module
- **Responsibilities**:
  - Searching for trains based on source, destination, and date.
  - Booking, modifying, and canceling tickets.
  - Generating unique PNRs for each booking.
- **Key Components**:
  - Reservation service.
  - Reservation database.

### 4.4 Payment Processing Module
- **Responsibilities**:
  - Handling secure payment transactions.
  - Supporting multiple payment methods.
- **Key Components**:
  - Payment gateway integration.
  - Payment database.

### 4.5 Notification Module
- **Responsibilities**:
  - Sending email and SMS notifications for booking confirmations, cancellations, and schedule changes.
- **Key Components**:
  - Notification service.

### 4.6 Reporting and Analytics Module
- **Responsibilities**:
  - Generating reports on bookings, cancellations, and revenue.
  - Providing analytics for passenger trends.
- **Key Components**:
  - Reporting service.
  - Analytics engine.

### 4.7 Admin Dashboard Module
- **Responsibilities**:
  - Providing a user-friendly interface for administrators to manage trains and monitor bookings.
- **Key Components**:
  - Admin dashboard frontend.
  - Backend APIs for admin operations.

## 5. User Interface Design

The user interface (UI) for the Railway Reservation System (RRS) is designed to be intuitive, user-friendly, and accessible. Below are the key UI components:

### 5.1 Passenger Interface
- **Home Page**:
  - Train search bar with fields for source, destination, and date.
  - Quick links to login, register, and view bookings.
- **Registration and Login Pages**:
  - Simple forms for user registration and login.
  - Password recovery option.
- **Train Search Results Page**:
  - List of available trains with details like train name, schedule, and seat availability.
  - Filters for sorting by time, price, and train type.
- **Booking Page**:
  - Form to select seats and confirm booking.
  - Payment gateway integration for secure transactions.
- **Booking History Page**:
  - List of past and upcoming bookings with options to modify or cancel.

### 5.2 Admin Interface
- **Admin Dashboard**:
  - Overview of system statistics like total bookings, revenue, and active users.
  - Quick links to manage trains and view reports.
- **Train Management Page**:
  - Forms to add, update, or delete train schedules.
  - List of existing trains with search and filter options.
- **Reports Page**:
  - Tools to generate and download reports on bookings, cancellations, and revenue.

### 5.3 Common Features
- **Navigation Bar**:
  - Persistent navigation bar with links to key sections.
  - User-specific options like "My Account" for passengers and "Admin Panel" for administrators.
- **Responsive Design**:
  - Optimized for both desktop and mobile devices.
- **Accessibility Features**:
  - Support for screen readers and keyboard navigation.
  - High-contrast mode for visually impaired users.