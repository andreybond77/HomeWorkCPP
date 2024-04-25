#include <iostream>
#include <string>
#include <vector>
using namespace std;
//Программный шаблон посредника
/*
class Mediator;

class User {
public:
    User(const std::string& name, Mediator* mediator) : name(name), mediator(mediator) {}

    void sendMessage(const std::string& message);

    void receiveMessage(const std::string& message) {
        std::cout << name << " received message: " << message << std::endl;
    }

private:
    std::string name;
    Mediator* mediator;
};

class Mediator {
public:
    void addUser(User* user) {
        users.push_back(user);
    }

    void sendMessage(User* sender, const std::string& message) {
        for (User* user : users) {
            if (user != sender) {
                user->receiveMessage(message);
            }
        }
    }

private:
    std::vector<User*> users;
};

void User::sendMessage(const std::string& message) {
    mediator->sendMessage(this, message);
}

int main() {
    Mediator mediator;

    User user1("User 1", &mediator);
    User user2("User 2", &mediator);

    mediator.addUser(&user1);
    mediator.addUser(&user2);

    user1.sendMessage("Hello!");
    user2.sendMessage("Hi there!");

    return 0;
}
*/
//Программный шаблон визитор
class Color
{
public:
    virtual void accept(class Visitor*) = 0;
};

class Red : public Color
{
public:
    /*virtual*/void accept(Visitor*);
    void eye()
    {
        cout << "Red::eye\n";
    }
};
class Blu : public Color
{
public:
    /*virtual*/void accept(Visitor*);
    void sky()
    {
        cout << "Blu::sky\n";
    }
};

class Visitor
{
public:
    virtual void visit(Red*) = 0;
    virtual void visit(Blu*) = 0;
};

class CountVisitor : public Visitor
{
public:
    CountVisitor()
    {
        m_num_red = m_num_blu = 0;
    }
    /*virtual*/void visit(Red*)
    {
        ++m_num_red;
    }
    /*virtual*/void visit(Blu*)
    {
        ++m_num_blu;
    }
    void report_num()
    {
        cout << "Reds " << m_num_red << ", Blus " << m_num_blu << '\n';
    }
private:
    int m_num_red, m_num_blu;
};

class CallVisitor : public Visitor
{
public:
    /*virtual*/void visit(Red* r)
    {
        r->eye();
    }
    /*virtual*/void visit(Blu* b)
    {
        b->sky();
    }
};

void Red::accept(Visitor* v)
{
    v->visit(this);
}

void Blu::accept(Visitor* v)
{
    v->visit(this);
}

int main()
{
    Color* set[] =
    {
      new Red, new Blu, new Blu, new Red, new Red, 0
    };
    CountVisitor count_operation;
    CallVisitor call_operation;
    for (int i = 0; set[i]; i++)
    {
        set[i]->accept(&count_operation);
        set[i]->accept(&call_operation);
    }
    count_operation.report_num();
}