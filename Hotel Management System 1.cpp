#include <iostream>
#include <string>
#include <iomanip>
#include <cmath>
using namespace std;

int workercount = 8;
int choice;
int count = 6;

// structs for manager;
struct manager {
    int id;
    string name;
    string username;
    string password;
    string role;
    string permissions;
};

// struct for receptionist;
struct receptionist {
    int id;
    string name;
    string username;
    string password;
    string role;
    string permissions;
};

// struct for worker;
struct worker {
    int id;
    string name;
    string contactinfo;
    float salary;
    string jobtitle;
};

// struct for resident;
struct resident {
    int id;
    string name;
    string contactinfo;
    string roomtype; // room type (single;double;triple)
    int durationofstay;
    string boardingoption; // (full board; half board; bed and breakfast)
    int roomid;
    float cost;
};


// struct for room;
struct room {
    int id;
    string type; // type (single;double;triple)
    string status; // Status (Available/Occupied)
    float price; // Room price per night
};



// Intializing data
// Define constants for array sizes
const int managers = 5;
const int receptionists = 5;
const int workers = 10;
const int residents = 100;
const int rooms = 25;

// Creating the Room Table array
// room prices
const float SP = 500.00;
const float DP = 650.00;
const float TP = 800.00;
const float FBP = 2.00;
const float HBP = 1.50;
const float BBP = 1.00;
//DP - Double Price    FB - Full board price multiplier

room roomtable[rooms] = {
    {1, "S", "O", SP}, {2, "D", "O", DP}, {3, "T", "O", TP},
    {4, "S", "O", SP}, {5, "D", "O", DP}, {6, "S", "A", SP},
    {7, "D", "A", DP}, {8, "T", "A", TP}, {9, "S", "A", SP},
    {10, "D", "A", DP}, {11, "S", "O", SP}, {12, "D", "O", DP},
    {13, "T", "O", TP}, {14, "S", "O", SP}, {15, "D", "O", DP},
    {16, "S", "A", SP}, {17, "D", "A", DP}, {18, "T", "A", TP},
    {19, "S", "A", SP}, {20, "D", "A", DP}, {21, "S", "O", SP},
    {22, "D", "O", DP}, {23, "T", "O", TP}, {24, "S", "A", SP},
    {25, "D", "A", DP}
};
// Creating the Worker Table array
worker workertable[workers] = {
   {1, "Charlie Green", "123-456-7890", 3000.00, "Housekeeper"},
   {2, "Emma White", "123-456-7891", 3200.00, "Housekeeper"},
   {3, "Liam Black", "123-456-7892", 2800.00, "Receptionist"},
   {4, "Noah Harris", "123-456-7893", 2500.00, "Waiter"},
   {5, "Olivia Lewis", "123-456-7894", 2700.00, "Waiter"},
   {6, "Ava Scott", "123-456-7895", 3500.00, "Maintenance"},
   {7, "Sophia Clark", "123-456-7896", 3100.00, "Cleaner"}

};
// Creating the Manager Table array
manager managertable[managers] = {
    {1, "John Doe", "jdoe", "password123", "Manager", "Full access"},
    {2, "Jane Smith", "jsmith", "password456", "Manager", "Full access"}
};

// Creating the Receptionist Table array
receptionist receptionisttable[receptionists] = {
    {1, "Mary Johnson", "mjohnson", "password789", "Receptionist", "View room status"},
    {2, "Alice Brown", "abrown", "password101", "Receptionist", "View room status"},
    {3, "Bob Williams", "bwilliams", "password112", "Receptionist", "View room status"}
};
//Creating the Resident Table array
resident residenttable[residents] = {
       {1, "Michael Adams", "987-654-3210", "S", 5, "FB", 1, 5000.00},
       {2, "Linda Green", "987-654-3211", "D", 7, "HB", 2, 6825.00},
       {3, "David Wilson", "987-654-3212", "T", 3, "BB", 3, 2400.00},
       {4, "Sarah Turner", "987-654-3213", "S", 10, "FB", 4, 10000.00},
       {5, "James Carter", "987-654-3214", "D", 4, "HB", 5, 3900.00}
};

const float maintainance = 1000.00;

receptionist receptionist1 = { 2121,"Hamada Ayman","hamada","hamada2121","Receptionist","1.Resident Management 2. Room Assignment 3.Calculate Costs" };
receptionist receptionist2 = { 2222,"Samah Ayman","samah","samah2222","Receptionist","1.Resident Management 2. Room Assignment 3.Calculate Costs" };

manager manager1 = { 1919,"Gerges Hany","gerges","gerges1919","Manager","1. Worker Management 2. View Worker Details" };
manager manager2 = { 2020,"Hanan Yousry","hanan","hanan2020","Manager","1. Track Income 2. Room Status Monitoring" };


void viewworkers() {
    if (workercount == 0) {
        cout << "no workers found. please add workers or initialize data.\n";
        return;
    }
    

    cout << "\n--- list of workers ---\n";
    for (int i = 0; i < workercount; i++) {
        if (workertable[i].id == 0)
            continue;
        cout << "worker id: " << workertable[i].id << "\n";
        cout << "name: " << workertable[i].name << "\n";
        cout << "contact: " << workertable[i].contactinfo << "\n";
        cout << "salary: " << workertable[i].salary << "\n";
        cout << "job title: " << workertable[i].jobtitle << "\n";
        cout << "----------------------\n";
    }
}

void addworker() {
    int workerid;
    cout << "enter worker id to add : ";
    
    cin >> workerid;
    if (workerid == 0) {
        cout << "this ID is invalid ";
        return;
    }

    for (int i = 0; i < workercount; i++) {
        if (workertable[i].id == workerid) {
            cout << "Id is already exist";
            return;
        }
    }
    workertable[workercount].id = workerid;
    cin.ignore();

    cout << "enter worker name: ";
    getline(cin, workertable[workercount].name);

    cout << "enter worker contact information (e.g., 01012345678): ";
    getline(cin, workertable[workercount].contactinfo);

    cout << "enter worker salary: ";
    cin >> workertable[workercount].salary;
    cin.ignore();

    cout << "enter worker job title: ";
    getline(cin, workertable[workercount].jobtitle);

    workercount++;
    cout << "worker added successfully!\n";
}

void editworker() {
    int workerid;
    cout << "please enter the worker id to edit: ";
    cin >> workerid;
    if (workerid == 0) {
        cout << "worker with ID 0 not found";
        return;
    }
    for (int i = 0; i < workercount; i++) {
        if (workertable[i].id == workerid) {
            cout << "editing worker: " << workertable[i].name << "\n";

            cout << "enter new name (or press enter to keep current): ";
            cin.ignore();
            string newname;
            getline(cin, newname);
            if (!newname.empty()) {
                workertable[i].name = newname;
            }

            cout << "enter new contact information (or press enter to keep current): ";
            string newcontactinfo;
            getline(cin, newcontactinfo);
            if (!newcontactinfo.empty()) {
                workertable[i].contactinfo = newcontactinfo;
            }

            cout << "enter new salary (or enter -1 to keep current): ";
            float newsalary;
            cin >> newsalary;
            if (newsalary >= 0) {
                workertable[i].salary = newsalary;
            }
            cin.ignore();

            cout << "enter new job title (or press enter to keep current): ";
            string newjobtitle;
            getline(cin, newjobtitle);
            if (!newjobtitle.empty()) {
                workertable[i].jobtitle = newjobtitle;
            }
            cout << "worker details updated successfully!\n";
            return;
        }
    }

    cout << "worker with id " << workerid << " not found.\n";
}

void deleteworker() {
    int workerid;
    cout << "please enter the worker id to delete: ";
    cin >> workerid;
    if (workerid == 0) {
        cout << "worker with ID 0 not found";
        return;
    }

    for (int i = 0; i < workercount; i++) {
        if (workertable[i].id == workerid) {
            for (int j = i; j < workercount - 1; j++) {
                workertable[j] = workertable[j + 1];
            }
            workercount--;
            cout << "worker deleted successfully.\n";
            return;
        }
    }

    cout << "worker with id " << workerid << " not found.\n";
}

void viewroomstatus() {


    for (int i = 0; i < rooms; i++) {
        cout << "room id: " << roomtable[i].id
            << ", type: " << roomtable[i].type
            << ", status: " << roomtable[i].status
            << ", price: $ " << roomtable[i].price << endl;
    }
}

void genreport(resident residenttable[], worker workertable[], int residents, int workers, int maintainance) {
    float tincome = 0;  // Total income from residents
    float tcost = 0;    // Total costs (maintenance + workers)
    int time = 1;
    bool monthly = 0;

    cout << "For weekly report press 1, for monthly press 2 \n";
    cin >> time;

    // Determine if the report is monthly
    if (time == 2)
        monthly = 1;
    else
        monthly = 0;

    // Calculate total income from residents
    for (int i = 0; i < residents; i++) {
        tincome += residenttable[i].cost;
    }

    // Add worker salaries to total cost
    for (int i = 0; i < workers; i++) {
        if (monthly) {
            tcost += 4 * workertable[i].salary;  // Quadruple salary for monthly report
        }
        else {
            tcost += workertable[i].salary;  // Use weekly salary for weekly report
        }
    }

    // Add maintenance costs (multiply by 4 for monthly reports)
    if (monthly) {
        tcost += 4 * maintainance;  // Monthly maintenance costs
    }
    else {
        tcost += maintainance;  // Weekly maintenance costs
    }

    // Calculate profit (income - costs)
    float profit = tincome - tcost;

    // Define width for alignment
    const int colWidth = 20;  // Set all columns to a width of 20 characters

    // Display the table headers with proper alignment
    cout << setw(colWidth) << "Resident ID"
        << setw(colWidth) << "Income"
        << setw(colWidth) << "Worker ID"
        << setw(colWidth) << "Costs" << endl;
    cout << " \n";

    // Display resident costs and worker salaries
    for (int m = 0; m < residents; m++) {
        cout << setw(colWidth) << residenttable[m].id
            << setw(colWidth) << residenttable[m].cost;
        if (m < workers) {
            cout << setw(colWidth) << workertable[m].id;
        }
        else {
            cout << setw(colWidth) << "No worker";
        }
        // Display worker salary (quadrupled if it's a monthly report)
        if (m < workers) {
            if (monthly) {
                cout << setw(colWidth) << 4 * workertable[m].salary << endl;  // Quadrupled salary for monthly
            }
            else {
                cout << setw(colWidth) << workertable[m].salary << endl;  // Weekly salary for weekly report
            }
        }
        else {
            cout << setw(colWidth) << "No worker" << endl;  // Display "No worker" for residents without workers
        }
    }

    // Display maintenance costs
    cout << "\n";
    if (monthly == 1)
        cout << "Maintenance Costs are: " << 4 * maintainance << endl;
    else
        cout << "Maintenance Costs are: " << maintainance << endl;

    // Print totals
    cout << setw(colWidth) << "Totals: "
        << setw(colWidth) << tincome
        << setw(colWidth) << " "
        << setw(colWidth) << tcost
        << setw(colWidth) << " ";
    cout << "Profit: " << profit << endl;
}
int main();


void manger1() {

    do {
        cout << "\n--------Main Menu--------\n";
        cout << "1. add worker\n";
        cout << "2. Edit worker\n";
        cout << "3. Delete worker\n";
        cout << "5 view workers\n";
        cout << "6. log out\n";
        cout << "7. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;
        switch (choice) {
        case 1:
            addworker();
            break;
        case 2:
            editworker();
            break;
        case 3:
            deleteworker();
            break;

        case 5:
            viewworkers();

            break;
        case 6:
         main();
        case 7:
            cout << " Exiting program. Goodbye\n";
            break;

        default:
            cout << "Invalid choice . try again.\n";

        }
    } while (choice != 7);


}




void manger2() {
    do {
        cout << "\n--------Main Menu--------\n";
        cout << " 1.to view rooms status\n";
        cout << " 2.to genreport\n";
        cout << " 3. log out\n";
        cout << " 4. Exit\n";
        cout << "Enter your choice: \n";
        cin >> choice;
        switch (choice) {
        case 1:
            viewroomstatus();
            break;
        case 2:
            genreport(residenttable, workertable, residents, workers, maintainance);

            break;

        case 3:
            main();

        case 4:
            cout << " Exiting program. Goodbye\n";
            break;

        default:
            cout << "Invalid choice . try again.\n";

        }
    } while (choice != 4);

}
bool managerlogin(manager manager1, manager manager2) {
    string username;
    string password;
    cout << "Enter username: ";
    cin.ignore();
    getline(cin, username);
    cout << "Enter password: ";
    getline(cin, password);
    if ((username == manager1.username && password == manager1.password) || (username == manager2.username && password == manager2.password)) {
        if (username == manager1.username) {
            cout << "Hello " << manager1.name << "!" << endl;
            manger1();
        }
        else {
            cout << "Hello " << manager2.name << "!" << endl;
            manger2();
        }

        return true;
    }
    return false;
}

void menu(resident newresident[], int& count, room rooms[], int roomcount, const int residents);

bool receptionistlogin(receptionist receptionist1, receptionist receptionist2,int& count) {
    string username;
    string password;
    cout << "Enter username: ";
    cin.ignore();
    getline(cin, username);
    cout << "Enter password: ";
    getline(cin, password);
    if ((username == receptionist1.username && password == receptionist1.password) || (username == receptionist2.username && password == receptionist2.password)) {
        if (username == receptionist1.username) {
            cout << "Hello " << receptionist1.name << "!" << endl;
            menu(residenttable, count, roomtable, rooms, residents);
         
        }
        else {
            cout << "Hello " << receptionist2.name << "!" << endl;
            menu(residenttable, count, roomtable, rooms, residents);
        }

        return true;
    }
    return false;
}
void makeroomavailable(room rooms[], int roomcount, int idroom) {
    for (int r = 0; r < roomcount; r++) {
        if (idroom == rooms[r].id) {
            rooms[r].status = "A";
            cout << "room with id: " << idroom << " is now Available\n";
            break;

        }
    }
}

void assignroom(resident newresident, room rooms[], int roomcount) {
    bool flag = false;
    for (int i = 0; i < roomcount; i++) {
        if (rooms[i].type == newresident.roomtype && rooms[i].status == "A") {
            rooms[i].status = "O";
            newresident.roomid = rooms[i].id;
            cout << "Room with id: " << rooms[i].id << " assigned to resident: " << newresident.name << " with id " << newresident.id << endl;
            flag = true;
            break;
        }
    }
    if (!flag)
        cout << "failed to assign room" << endl;
}

void calculatecost(resident& r) {
    float cost = 0;
    if (r.roomtype == "S") cost = SP;
    else if (r.roomtype == "D") cost = DP;
    else if (r.roomtype == "T") cost = TP;
    cost = cost * r.durationofstay;
    if (r.boardingoption == "FB") cost *= FBP;
    else if (r.boardingoption == "HB") cost *= HBP;
    else if (r.boardingoption == "BB") cost *= BBP;
    r.cost = cost;
    cout << "This Resident's total cost will amount to: " << cost << endl;
}

void addresident(resident newresident[], int& count, int roomcount, room rooms[]) {
    int size;
    cout << "Please enter number of residents you want to add: ";
    cin >> size;
    while (size <= 0) {
        cout << "invalid numbers try again: ";
        cin >> size;
    }
    cin.ignore();
    for (int i = 0; i < size; i++) {
        newresident[count - 1].id = count;
        cout << "id: " << newresident[count - 1].id << endl;
        cout << "name of resident: ";
        getline(cin, newresident[count - 1].name);
        cout << "contact info: ";
        getline(cin, newresident[count - 1].contactinfo);
        cout << "room type\nS:single \nD:double\nT:triple\n resident chose: ";
        getline(cin, newresident[count - 1].roomtype);
        while (newresident[count - 1].roomtype != "S" && newresident[count - 1].roomtype != "D" && newresident[count - 1].roomtype != "T") {
            cout << "invalid type enter again";
            getline(cin, newresident[count - 1].roomtype);
        }

        cout << "duration of stay: ";
        cin >> newresident[count - 1].durationofstay;
        while (newresident[count - 1].durationofstay <= 0) {
            cout << "invalid try again: ";
            cin >> newresident[count - 1].durationofstay;
        }
        cin.ignore();
        cout << "boarding option\nFB:Full-Board\nHB:half-board\nBB:Bed and breakfast\nresident chose: ";
        getline(cin, newresident[count - 1].boardingoption);
        while (newresident[count - 1].boardingoption != "FB" && newresident[count - 1].boardingoption != "HB" && newresident[count - 1].boardingoption != "BB") {
            cout << "invalid type enter again";
            getline(cin, newresident[count - 1].boardingoption);
        }
        calculatecost(newresident[count - 1]);
        assignroom(newresident[count - 1], rooms, roomcount);
        count++;
    }
}

void deleteresident(resident newresident[], int& count, room rooms[], int roomcount) {
    int ids;
    int idroom;
    bool flag = false;
    cout << "enter id: ";
    cin >> ids;
    for (int i = 0; i < count; i++) {
        if (ids == 0) {
            cout << "id not found";
            break;
        }

        if (ids == newresident[i].id) {
            flag = true;
            idroom = newresident[i].roomid;
            for (int j = i + 1; j < count; j++) {

                newresident[j - 1] = newresident[j];
            }

            makeroomavailable(rooms, roomcount, idroom);
            cout << "resident# " << ids << " is deleted" << endl;
            break;
        }
    }
    if (!flag) {
        cout << "resident not found" << endl;
    }
}
void viewresidents(resident residenttable[], const int residents) {
    int wid = 15; // column width
    cout << "ID" << setw(wid) << "Name" << setw(wid) << "Contact" << setw(wid) << "Room type" << setw(wid) << "Duration" << setw(wid) << "Boarding"
        << setw(wid) << "Room ID" << setw(wid) << "Cost" << endl;
    for (int i = 0; i < residents; i++) {
        if (residenttable[i].id == 0)
            break;
        else {
            cout << residenttable[i].id << setw(wid) << residenttable[i].name << setw(wid) << residenttable[i].contactinfo << setw(wid) << residenttable[i].roomtype
                << setw(wid) << residenttable[i].durationofstay << setw(wid) << residenttable[i].boardingoption
                << setw(wid) << residenttable[i].roomid << setw(wid) << residenttable[i].cost << endl;
        }

    }
}

void editresident(resident newresident[], int& count, room rooms[], int roomcount) {
    int ids;
    int option;
    bool flag = false;
    do {
        int idroom;
        cout << "choose numbers from 1 to 5 to edit resident data\n1 to edit name\n2 to edit contact info\n3 to edit room type\n4 to edit duration of stay\n5 to edit boarding option\n6 to exit\n";
        cin >> option;
        cout << "please enter id: ";
        cin >> ids;

        while (option <= 0 || option > 6) {
            cout << "invalid option please try again: ";
            cin >> option;
        }
        for (int i = 0; i < count; i++) {

            if (ids == newresident[i].id) {
                idroom = newresident[i].roomid;

                switch (option) {
                case 1:
                    cin.ignore();
                    cout << "edit name: ";
                    getline(cin, newresident[i].name);
                    flag = true;
                    break;
                case 2:
                    cout << "edit contact info: ";
                    getline(cin, newresident[i].contactinfo);
                    flag = true;
                    break;
                case 3:
                    cout << "room type\nS:single\nD:double\nT:triple\nresident choose: ";
                    flag = true;
                    cin.ignore();
                    getline(cin, newresident[i].roomtype);
                    while (newresident[i].roomtype != "S" && newresident[i].roomtype != "D" && newresident[i].roomtype != "T") {
                        cout << "invalid type enter again";
                        getline(cin, newresident[i].roomtype);
                    }
                    makeroomavailable(rooms, roomcount, idroom);
                    calculatecost(newresident[i]);
                    assignroom(newresident[i], rooms, roomcount);

                    break;

                case 4:
                    cout << "edit duration of stay in days: ";
                    flag = true;
                    cin >> newresident[i].durationofstay;
                    while (newresident[i].durationofstay <= 0) {
                        cout << "invalid try again: ";
                        cin >> newresident[i].durationofstay;
                        makeroomavailable(rooms, roomcount, idroom);
                        calculatecost(newresident[i]);
                        assignroom(newresident[i], rooms, roomcount);
                    }
                    cin.ignore();
                    break;
                case 5:
                    cin.ignore();
                    flag = true;
                    cout << "boarding option\nFB:Full-Board\nHB:half-board\nBB:Bed and breakfast\nresident chose: ";
                    getline(cin, newresident[i].boardingoption);
                    while (newresident[i].boardingoption != "FB" && newresident[i].boardingoption != "HB" && newresident[i].boardingoption != "BB") {
                        cout << "invalid type enter again";
                        getline(cin, newresident[i].boardingoption);
                    }
                    makeroomavailable(rooms, roomcount, idroom);
                    calculatecost(newresident[i]);
                    assignroom(newresident[i], rooms, roomcount);
                    break;
                case 6:
                    cout << "exit";
                    break;

                default:
                    cout << "error" << endl;
                    break;
                }
                break;


            }
        }
        if (option != 6) {
            if (flag) {
                cout << "resident# " << ids << " data edited" << endl;
                break;
            }
            else
                cout << "resident not found" << endl;
        }

    } while (option != 6);
}

void menu(resident newresident[], int& count, room rooms[], int roomcount, const int residents) {
    int option;
    do {
        cout << "\nchoose 1 to add resident\nchoose 2 to edit resident\nchoose 3 to delete resident\nchoose 4 to display residents\nchoose 5 to exit\nchoose:";
        cin >> option;
        while (option <= 0 || option > 5) {
            cout << "invalid option try again: ";
            cin >> option;
        }
        switch (option) {
        case 1:
            cout << "welcome to add resident menu\n";
            addresident(newresident, count, roomcount, rooms);
            break;
        case 2:
            cout << "welcome to edit resident menu\n";
            editresident(newresident, count, rooms, roomcount);
            break;
        case 3:
            cout << "welcome to delete resident menu\n";
            deleteresident(newresident, count, rooms, roomcount);
            break;
        case 4:
            viewresidents(newresident, residents);
            break;
        case 5:
            cout << "exit";
            break;
        default:
            cout << "error" << endl;
        }
    } while (option != 5);
}


int main() {

    int count = 6;


  
main_menu:
    cout << setw(50) << "Welcome!\n";
    cout << "What do you want?" << endl << "1. Manager Login" << endl << "2. Receptionist Login" << endl << "3. Exit" << endl;
    cin >> choice;
    switch (choice) {
    case 1:
    try_again1:
        if (managerlogin(manager1, manager2)) {
            // cout << "yes\n" << endl;
            break;
        }
        else {
            cout << "Invalid Data\n";
            cout << "To retry press 1, to go to main menu press 2, to exit press any another number\n";
            cin >> choice;
            if (choice == 1)
                goto try_again1;
            else if (choice == 2)
                goto main_menu;
            else
                goto end;

        }

    case 2:
    try_again2:
        if (receptionistlogin(receptionist1, receptionist2,count)) {
            //    cout << "yes" << endl;
            break;
        }
        else {
            cout << "Invalid Data\n";
            cout << "To retry press 1, to go to main menu press 2, to exit press any another number\n";
            cin >> choice;
            if (choice == 1)
                goto try_again2;
            else if (choice == 2)
                goto main_menu;
            else
                goto end;
        }
    case 3:
    end:
        cout << "Bye\n";
        exit(0);
    default :
        cout << "Invalid Input, to retry press 1, to exit press any another number ";
        cin >> choice;
        if (choice == 1) {
            goto main_menu;
        }
        else
            goto end;
    }
    return 0;
}