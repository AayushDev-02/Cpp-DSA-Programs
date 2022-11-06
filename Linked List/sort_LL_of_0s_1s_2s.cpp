#include <iostream>
using namespace std;

Node *sort(Node *head)
{
    while (head == NULL)
    {
        return head;
    }

    Node *temp = head;
    int zero = 0;
    int one = 0;
    int two = 0;

    while (temp != NULL)
    {

        if (temp->data == 0)
        {
            zero++;
        }
        else if (temp->data == 1)
        {
            one++;
        }
        else if (temp->data == 2)
        {
            two++;
        }

        temp = temp->next;
    }

    temp = head;

    while (temp != NULL)
    {

        if (zero != 0)
        {

            temp->data = 0;
            zero--;
        }
        else if (one != 0)
        {

            temp->data = 1;
            one--;
        }
        else if (two != 0)
        {

            temp->data = 2;
            two--;
        } 
        
        temp = temp->next;
    }

    return head;
}

int main()
{
}