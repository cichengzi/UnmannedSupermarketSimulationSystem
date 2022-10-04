#include"test.h"

bool Tester::assertTrueDouble(double a, double b) {
    return -1e-6 <= a - b && a - b <= 1e-6;
}

bool Tester::assertTrueString(std::string a, std::string b) {
    return a == b;
}

bool Tester::assertTrueUserType(UserType a, UserType b) {
    return a == b;
}

bool Tester::assertTrueInt(int a, int b) {
    return a == b;
}

bool Tester::testAddUser() {
    Supermarket supermarket;
    User user1 = User("孙琪", GeneralUser, 100);
    User user2 = User("甄思琪", Administrator, 200);
    supermarket.addUser(user1);
    supermarket.addUser(user2);
    if (!assertTrueInt((int) supermarket.getUsers().size(), 2))
        return false;
    return true;
}

bool Tester::testReadUsers() {
    Supermarket supermarket;
    User user1 = User("孙琪", GeneralUser, 100);
    User user2 = User("甄思琪", Administrator, 200);
    supermarket.addUser(user1);
    supermarket.addUser(user2);
    supermarket.saveUsers();
    supermarket.clearUsers();
    for (User user: supermarket.readUsers()) {
        supermarket.addUser(user);
    }
    if (!assertTrueString(supermarket.getUser(0).getName(), "孙琪"))
        return false;
    if (!assertTrueString(supermarket.getUser(1).getName(), "甄思琪"))
        return false;
    if (!assertTrueUserType(supermarket.getUser(0).getUserType(), GeneralUser))
        return false;
    if (!assertTrueUserType(supermarket.getUser(1).getUserType(), Administrator))
        return false;
    if (!assertTrueDouble(supermarket.getUser(0).getBalance(), 100))
        return false;
    if (!assertTrueDouble(supermarket.getUser(1).getBalance(), 200))
        return false;
    return true;
}

bool Tester::testClearAllUsers() {
    Supermarket supermarket;
    User user1 = User("孙琪", GeneralUser, 100);
    User user2 = User("甄思琪", Administrator, 200);
    supermarket.addUser(user1);
    supermarket.addUser(user2);
    supermarket.clearUsers();
    if (!assertTrueInt((int)supermarket.getUsers().size(), 0))
        return false;
    return true;
}

bool Tester::testGetUser() {
    Supermarket supermarket;
    User user1 = User("孙琪", GeneralUser, 100);
    User user2 = User("甄思琪", Administrator, 200);
    supermarket.addUser(user1);
    supermarket.addUser(user2);
    if (!assertTrueString(supermarket.getUser(0).getName(), "孙琪"))
        return false;
    if (!assertTrueString(supermarket.getUser(1).getName(), "甄思琪"))
        return false;
    return true;
}

bool Tester::testSaveUsers() {
    Supermarket supermarket;
    User user1 = User("孙琪", GeneralUser, 100);
    User user2 = User("甄思琪", Administrator, 200);
    supermarket.addUser(user1);
    supermarket.addUser(user2);
    supermarket.saveUsers();
    FILE* fr = fopen("../data/users.txt", "r");
    int line_count = 0;
    char s[1000];
    while (fgets(s, 1000, fr) != NULL) {
        line_count++;
    }
    if (line_count != 2)
        return false;
    return true;
}

bool Tester::runAllTest() {
    if (!testAddUser())
        return false;
    if (!testReadUsers())
        return false;
    if (!testClearAllUsers())
        return false;
    if (!testGetUser())
        return false;
    if (!testSaveUsers())
        return false;
    return true;
}
