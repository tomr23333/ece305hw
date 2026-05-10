#include <iostream>
#include <string>
#include <vector>
#include <stack>

using namespace std;

struct Node
{
    string data;
    Node* left;
    Node* right;
};

bool isOperator(string token);
bool isNumber(string token);
int precedence(string token);
Node* createNode(string data);

vector<string> infixToPostfix(vector<string> infix);
Node* buildTree(vector<string> postfix);

void postorder(Node* root);
void postorderToVector(Node* root, vector<string>& postfix);

int evaluatePostfix(vector<string> postfix);

int main(){
    vector<string> infix;
    vector<string> postfix;
    vector<string> treePostfix;
    string token;
    Node* root;
    cout << "input expression， space between letter add= afterr" << endl;
    cin >> token;
    while (token != "="){
        infix.push_back(token);
        cin >> token;
    }

    postfix = infixToPostfix(infix);
    root = buildTree(postfix);
    cout << endl;
    cout << "postfix expression:" << endl;
    postorder(root);
    cout << endl;
    postorderToVector(root, treePostfix);
    cout << endl;
    cout << evaluatePostfix(treePostfix) << endl;
    return 0;
}

bool isOperator(string token){
    if ((token == "+") || (token == "-")||(token == "*")|| (token == "/")){
        return true;
    }
    else{
        return false;
    }
}

bool isNumber(string token){
    if ((token == "(") || (token == ")")||(isOperator(token)))
    {
        return false;
    }
    else{
        return true;
    }
}

int precedence(string token){
    if ((token == "*" )||(token == "/"))
    {
        return 2;
    }
    else if ((token == "+")||(token == "-")){
        return 1;
    }
    else{
        return 0;
    }
}

Node* createNode(string data){
    Node* newNode = new Node();
    newNode->data = data;
    newNode->left = nullptr;
    newNode->right = nullptr;
    return newNode;
}

vector<string> infixToPostfix(vector<string> infix){
    vector<string> postfix;
    stack<string> operators;
    string token;
    string topOperator;

    for (int i = 0; i < infix.size(); i++){
        token = infix[i];
        if (isNumber(token)){
            postfix.push_back(token);
        }
        else if (token == "("){
            operators.push(token);
        }
        else if (token == ")"){
            while (!operators.empty()){
                topOperator = operators.top();
                if (topOperator != "("){
                    postfix.push_back(topOperator);
                    operators.pop();
                }
                else{
                    break;
                }
            }

            if (!operators.empty()){
                operators.pop();
            }
        }
        else if (isOperator(token)){
            while (!operators.empty()){
                topOperator = operators.top();

                if (topOperator == "("){
                    break;
                }

                if (precedence(topOperator) >= precedence(token)){
                    postfix.push_back(topOperator);
                    operators.pop();
                }
                else{
                    break;
                }
            }

            operators.push(token);
        }
    }

    while (!operators.empty()){
        postfix.push_back(operators.top());
        operators.pop();
    }
    return postfix;
}

Node* buildTree(vector<string> postfix){
    stack<Node*> treeStack;
    string token;
    Node* newNode;
    Node* rightNode;
    Node* leftNode;

    for (int i = 0; i < postfix.size(); i++){
        token = postfix[i];
        if (isNumber(token)){
            newNode = createNode(token);
            treeStack.push(newNode);
        }
        else if (isOperator(token))
        {
            rightNode = treeStack.top();
            treeStack.pop();
            leftNode = treeStack.top();
            treeStack.pop();
            newNode = createNode(token);
            newNode->left = leftNode;
            newNode->right = rightNode;
            treeStack.push(newNode);
        }
    }
    return treeStack.top();
}

void postorder(Node* root)
{
    if (root == nullptr)
    {
        return;
    }

    postorder(root->left);
    postorder(root->right);

    cout << root->data << " ";
}

void postorderToVector(Node* root, vector<string>& postfix)
{
    if (root == nullptr)
    {
        return;
    }

    postorderToVector(root->left, postfix);
    postorderToVector(root->right, postfix);

    postfix.push_back(root->data);
}

int evaluatePostfix(vector<string> postfix)
{
    stack<int> numbers;

    string token;
    int leftNumber;
    int rightNumber;
    int answer;

    for (int i = 0; i < postfix.size(); i++)
    {
        token = postfix[i];

        if (isNumber(token))
        {
            numbers.push(stoi(token));
        }
        else if (isOperator(token))
        {
            rightNumber = numbers.top();
            numbers.pop();

            leftNumber = numbers.top();
            numbers.pop();

            if (token == "+")
            {
                answer = leftNumber + rightNumber;
            }
            else if (token == "-")
            {
                answer = leftNumber - rightNumber;
            }
            else if (token == "*")
            {
                answer = leftNumber * rightNumber;
            }
            else if (token == "/")
            {
                answer = leftNumber / rightNumber;
            }

            numbers.push(answer);
        }
    }

    return numbers.top();
}

