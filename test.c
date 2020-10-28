#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*************************TOKEN STRUCT IMPORTS******************************/
#define MAX 100

char *ha[13][2];
char *op[16][2]; //FOR KEYWORD

typedef struct token
{ //TOKEN STRUCTURE
    char lexeme[200];
    char token[200];
    int lineno;
    struct token *next;
} token;

token *head = NULL;
token *tail = NULL; //Head, Tail of LinkedList for TokenStream

/**************************END TOKEN STRUCT***************************************/

/**************************TOKEN FUNC IMPORTS*****************************************************/
<<<<<<< HEAD
char *getToken(char *lexeme)
{
    char c = lexeme[0];
    int flag = 0;

    if ((c >= '0' && c <= '9') || strlen(lexeme) > 1 && c == '-' && (lexeme[1] >= '0' && lexeme[1] <= '9'))
        return "NUM";
    else if (flag == 0)
=======
char * getToken(char *lexeme){
    char c=lexeme[0];
    int flag=0;
   
    if((c>='0'&&c<='9')||strlen(lexeme)>1&&c=='-'&&(lexeme[1]>='0'&&lexeme[1]<='9'))
    return "NUM";
    else if(flag==0)
>>>>>>> b5201d7a1fdbe88476c185ec4c82aa191e8e0159
    {
        for (int i = 0; i < 13; i++)
            if (strcmp(lexeme, ha[i][0]) == 0)
                return ha[i][1];

        flag = 1;
    }
    if (flag == 1)
    {
        for (int i = 0; i < 16; i++)
        {
            if (strcmp(lexeme, op[i][0]) == 0)
                return op[i][1];
        }
        flag = 2;
    }
    if (flag == 2)
    {
        char d = lexeme[0];
        int i = 1;
        if (d == '_' || (d >= 65 && d <= 90) || (d >= 97 && d <= 122))
        {
            while (lexeme[i] != '\0')
            {
                d = lexeme[i];
                if ((i < 20) && (d == '_' || (d >= 65 && d <= 90) || (d >= 97 && d <= 122) || (d >= 48 && d <= 57)))
                {
                    i++;
                    continue;
                }
                else
                    return "ERROR";
            }
            return "ID";
        }
    }
    return "Error";
}

void printLinkedList()
{ //Test function for printing entire LinkedList of Tokens
    token *temp = head;
    printf("\n NOW PRINTING \n\n");
    while (temp != NULL)
    {
        printf("%s         ->       %s             --->>         %d\n", temp->lexeme, temp->token, temp->lineno);
        temp = temp->next;
    }
}
token *createNode(char *lexeme, int lineno)
{ //Return Dynamically Created Record for TOKEN
    token *a;
    a = (token *)malloc(sizeof(token));
    strcpy(a->lexeme, lexeme);
    strcpy(a->token, getToken(a->lexeme)); //To be hashed
    a->lineno = lineno;
    a->next = NULL;
    return a;
}
token *insertNode(token *node)
{ //Inserts Node to LinkedList Head, Tail USED
    if (head == NULL && tail == NULL)
    {
        head = tail = node;
        return head;
    }
    else
    {
        tail->next = node;
        tail = node;
    }
    return head;
}
void tokeniseSourcecode(char a[100], token *head)
{ //Function for File Redaing and creating LinkedList of Tokens
    FILE *fp;
    token *s;
    int count = 0;
    char buff[1000];
    fp = fopen(a, "r+");
    if (fp == NULL)
    {
        printf("ERRROR\n");
    }
    while (fscanf(fp, "%[^\n]\n", buff) != EOF)
    {
        count++;
        char *token_split;
        token_split = strtok(buff, " ");
        while (token_split != NULL)
        {
            if (token_split != NULL)
            {
                s = createNode(token_split, count);
                insertNode(s);
            }
            token_split = strtok(NULL, " ");
        }
    }
    //printLinkedList();
    fclose(fp);
}
/**************************END TOKEN FUNC IMPORTS***********************************************/

/**********************GRAMMAR STRUCT IMPORTS************************/
#define TOTAL_TERMINALS 35
#define TOTAL_NON_TERMINALS 37
#define NON_TERMINALS 37

char *TerminalMap[] =
    {
        "PROGRAM",
        "BROP",
        "BRCL",
        "CURLYOP",
        "CURLYCL",
        "EQUALS",
        "DECLARE",
        "ID",
        "COLON",
        "LIST",
        "OF",
        "VARIABLES",
        "SEMICOLON",
        "ARRAY",
        "INTEGER",
        "SQOP",
        "DD",
        "SQCL",
        "JAGGED",
        "R1",
        "NUM",
        "REAL",
        "BOOLEAN",
        "PLUS",
        "MINUS",
        "DIVIDE",
        "MUL",
        "SIZE",
        "VALUES",
        "AND",
        "OR",
        "EPSILON"};
char *NonTerminalMap[] =
    {
        "s",
        "start",
        "declaration",
        "declaration_stmt",
        "assignment",
        "assignment_stmt",
        "primitive",
        "single_primitive",
        "multi_primitive",
        "array",
        "single_array",
        "multi_array",
        "array_dim",
        "jagged_array",
        "jagged_2d_array",
        "single_jagged_2d_array",
        "multi_jagged_2d_array",
        "jagged_3d_array",
        "single_jagged_3d_array",
        "multi_jagged_3d_array",
        "jagged_2d_dim",
        "jagged_3d_dim",
        "jag_lines",
        "jag_line",
        "jag_list",
        "num_list",
        "num_id",
        "var_list",
        "arr_pid",
        "idx",
        "type",
        "expression",
        "arithmetic_expression",
        "term",
        "factor",
        "op1",
        "op2",
        "boolean_expression",
        "or_expression",
        "fact_bool",
        "not_app"};

typedef enum
{
    PROGRAM,
    BROP,
    BRCL,
    CURLYOP,
    CURLYCL,
    EQUALS,
    DECLARE,
    ID,
    COLON,
    LIST,
    OF,
    VARIABLES,
    SEMICOLON,
    ARRAY,
    INTEGER,
    SQOP,
    DD,
    SQCL,
    JAGGED,
    R1,
    NUM,
    REAL,
    BOOLEAN,
    PLUS,
    MINUS,
    DIVIDE,
    MUL,
    SIZE,
    VALUES,
    AND,
    OR,
    EPSILON
} Terminal;

typedef enum
{
    s,
    start,
    declaration,
    declaration_stmt,
    assignment,
    assignment_stmt,
    primitive,
    single_primitive,
    multi_primitive,
    array,
    single_array,
    multi_array,
    array_dim,
    jagged_array,
    jagged_2d_array,
    single_jagged_2d_array,
    multi_jagged_2d_array,
    jagged_3d_array,
    single_jagged_3d_array,
    multi_jagged_3d_array,
    jagged_2d_dim,
    jagged_3d_dim,
    jag_lines,
    jag_line,
    jag_list,
    num_list,
    num_id,
    var_list,
    arr_pid,
    idx,
    type,
    expression,
    arithmetic_expression,
    term,
    factor,
    op1,
    op2,
    boolean_expression,
    or_expression,
    fact_bool,
    not_app
} NonTerminal;

typedef union SYMBOL
{
    Terminal t;
    NonTerminal nt;
} symbol;

typedef struct RULE // Single Node of a rule in RHS
{
    int isterm; // 0=Non-Term  // 1=Terminal
    symbol type;
    struct RULE *next;
} rule;

// wrapper for a complete rule
typedef struct GRULES // Linked list of mutiple rules corresponding to a single LHS
{
    rule *head;
    struct GRULES *next;
} grules;

typedef struct // Derivation of a particular single LHS
{
    NonTerminal nt;
    //char nonTerminal[100];
    grules *head;
} grammar;
/***********GRAMMAR STRUCT IMPORTS END***************/

/*****************************FUNCTION GRAMMAR IMPORTS**********************/
void substring(char *a, char *b, int str, int end)
{
    int c = 0;
    for (int i = str; i <= end; i++)
    {
        a[c++] = b[i];
    }
    a[c] = '\0';
}

int find(char *str, int isterm)
{

    //Terminal
    if (isterm == 1)
    {
        for (int i = 0; i < TOTAL_TERMINALS; i++)
        {
            if (strcmp(str, TerminalMap[i]) == 0)
                return i;
        }
    }

    //Non terminal
    else
    {
        for (int i = 0; i < TOTAL_NON_TERMINALS; i++)
        {
            if (strcmp(str, NonTerminalMap[i]) == 0)
                return i;
        }
    }
    printf("Error %s\n", str);
    return 0;
}
void readGrammar(char a[100], grammar *G)
{
    FILE *fp;
    int count = 0;
    int count2 = 0;
    char buff[1000];
    char tmp[100];
    char tmp2[100];
    fp = fopen(a, "r+");
    if (fp == NULL)
    {
        printf("ERRROR\n");
        return;
    }
    char *grammar_split = NULL;
    grammar *gramcurr = G;
    grules *grulescurr = NULL;
    rule *rulecurr = NULL;
    while (fscanf(fp, "%[^\n]\n", buff) != EOF)
    {
        //printf("%s\n", buff);
        count++;
        grammar_split = strtok(buff, " ");
        if (grammar_split == NULL)
        {
            //printf("NULL\n");
        }
        if (grammar_split != NULL)
        {
            //printf("%s\n", grammar_split);
            substring(tmp, grammar_split, 1, strlen(grammar_split) - 2);
            //printf("%s %s\n", grammar_split, tmp);
        }
        if (count == 1)
        {
            //Initialsing grammar
            //printf("%s %s\n", grammar_split, tmp);
            gramcurr->nt = find(tmp, 0); //Initialised nt
            grulescurr = malloc(sizeof(grules));
            gramcurr->head = grulescurr; // Initialised head

            //Initialising grules
            rulecurr = malloc(sizeof(rule));
            grulescurr->head = rulecurr;
            grulescurr->next = NULL;

            //Initialising rule
            rulecurr->next = NULL;
        }

        else if (gramcurr->nt == find(tmp, 0))
        {
            //Need to make a new grules for the same LHS
            grulescurr->next = malloc(sizeof(grules));
            grulescurr = grulescurr->next;
            //Initialsing a new node of grules
            grulescurr->next = NULL;
            //ruleprev = NULL;
            rulecurr = malloc(sizeof(rule));
            rulecurr->next = NULL;
            grulescurr->head = rulecurr;
        }
        else
        {
            //Need to go add a new fresh rule for a fresh and juicy new LHS
            gramcurr++;
            //Initialsing grammar
            gramcurr->nt = find(tmp, 0); //Initialised nt
            //printf("%s <--->\n", NonTerminalMap[gramcurr->nt]);
            grulescurr = malloc(sizeof(grules));
            gramcurr->head = grulescurr; // Initialised head

            //Initialising grules
            rulecurr = malloc(sizeof(rule));
            grulescurr->head = rulecurr;
            grulescurr->next = NULL;

            //Initialising rule
            rulecurr->next = NULL;
            //ruleprev = NULL;
        }

        while (grammar_split != NULL)
        {
            grammar_split = strtok(NULL, " ");
            if (grammar_split != NULL)
            {
                if (strcmp(grammar_split, "=>") == 0)
                {
                    //printf("=>\n");
                    continue;
                }
                count2++;
                if (count2 != 1)
                {
                    rulecurr->next = malloc(sizeof(rule));
                    rulecurr = rulecurr->next;
                    rulecurr->next = NULL;
                }
                if (grammar_split[0] == '<')
                {
                    //printf("NONTERMINAL\n");
                    substring(tmp2, grammar_split, 1, strlen(grammar_split) - 2);
                    rulecurr->isterm = 0;
                    rulecurr->type.nt = find(tmp2, 0);
                }
                else
                {
                    //printf("TERMINAL\n");
                    rulecurr->isterm = 1;
                    rulecurr->type.t = find(grammar_split, 1);
                }
            }
        }
        count2 = 0;
    }
    fclose(fp);
    return;
}

/********************GRAMMAR FUNC END**********************************/

typedef enum
{
    Static,
    Dynamic,
    N_A
} bind_info;

char string_bind[3][25] = {
    "Static",
    "Dynamic",
    "NotApplicable"};

typedef union
{
    int *_line;
    int **jag_line; //jagged
} jagged_type;

<<<<<<< HEAD
typedef struct
{
    int dim;         //--4
    int **dim_bound; //(7,4),(3,4),(),() 4X2
    char **l_indexes;
    char **u_indexes;
} array_record;
=======
typedef struct {
    int dim;//--4
    int ** dim_bound;//(7,4),(3,4),(),() 4X2
    char **l_indexes;
    char **u_indexes;
}array_record;
>>>>>>> b5201d7a1fdbe88476c185ec4c82aa191e8e0159

typedef struct
{
    int dim; //2d or 3d ke liye tagg--
    int r1_low;
    int r1_high;
    jagged_type dim_bound;

} jagged_array_record;

typedef union type_Expression_record
{
    Terminal primitive_type; //INT<BOOL<REAL
    array_record arr_record;
    jagged_array_record j_arr_record;
} type_Expression_record;

typedef struct TypeExpression
{
    NonTerminal tag; ///primitive,array,jagged
    bind_info info;  //static dyanmic
    type_Expression_record record;
} TypeExpression;

typedef struct TypeExpressionTable
{
    char var_name[200]; //extra
    NonTerminal tag;
    bind_info info;
    type_Expression_record record;
} TypeExpressionTable;

/***************TYPE EXPRESSION TABLE AND STRUCTS**********************/

/************************** STRUCTURE DEFINITIONS *****************************/
// Terminal Nodes
typedef struct terminalNode
{
    Terminal t;
    char lexeme[100];
    int line_num;
} TerminalNode;

// NonTerminal Nodes
typedef struct nonTerminalNode
{
    NonTerminal nt;
    grules *expRule; // for getting the rule used in parsing

} NonTerminalNode;

// Union for Term / NonTerm Nodes
typedef union nodeType
{
    TerminalNode terminal;
    NonTerminalNode nonTerminal;
} NodeType;

// ParseTree Node
typedef struct treeNode
{
<<<<<<< HEAD
    int isTerm;    // tag for term/non_term and leaf / non_leaf
    NodeType Node; // Details corresponding to a Terminal or a NonTerminal Node

    //TypeExpression t; // to be done//done
    // only for NonTerminal or Both ??

    struct treeNode *parent;  // parent of the node
    struct treeNode *sibling; // right sibling of the node

    //for linkedlist of children
    struct treeNode *firstChild;
=======
	int isTerm; // tag for term/non_term and leaf / non_leaf
	NodeType Node;	// Details corresponding to a Terminal or a NonTerminal Node
	
	//TypeExpression t; // to be done//done
	// only for NonTerminal or Both ??
	
	struct treeNode * parent; // parent of the node
	struct treeNode * sibling; // right sibling of the node
	
	//for linkedlist of children
	struct treeNode* firstChild;
>>>>>>> b5201d7a1fdbe88476c185ec4c82aa191e8e0159
    TypeExpression exp_type;

} parseTree;

/**********************STRUCTURE END*********************************************/

/*******************************FUNCTIONS*************************************/

void deleteSubtree(parseTree *node)
{
    if (node == NULL)
        return;
    //delete all the children here
    parseTree *child = node->firstChild;
    while (child != NULL)
    {
        parseTree *nextChild = child->sibling;
        deleteSubtree(child);
        child = nextChild;
    }
    free(child);
}

parseTree *createTreeNode(rule *curr, parseTree *p)
{
    parseTree *node = malloc(sizeof(parseTree));
    node->isTerm = curr->isterm;

    node->parent = p;
    node->firstChild = NULL;
    node->sibling = NULL;
    node->exp_type.tag = not_app;

    if (curr->isterm)
    {
        node->Node.terminal.t = curr->type.t;
    }
    else
    {
        node->Node.nonTerminal.nt = curr->type.nt;
    }

    return node;
}
token *posToken;
parseTree *createParseTree(parseTree *p, grammar *G)
{
    if (posToken == NULL)
        return NULL;

    // Check if the current node is a terminal
    // no need to expand the node
    if (p->isTerm)
    {

        //printf("TERMINAL: %s %s\n", p->Node.terminal.lexeme, TerminalMap[p->Node.terminal.t]);
        if (p->Node.terminal.t == EPSILON)
            return p;
        else if ((p->Node).terminal.t == find(posToken->token, 1))
        {
            // PRINTING
            printf("TERMINAL: %s %s\n", p->Node.terminal.lexeme, TerminalMap[p->Node.terminal.t]);
            //printf("TERMINAL: %s \n", TerminalMap[p->Node.terminal.t]);
            posToken = posToken->next;
            return p;
        }
        else
        {
            return NULL;
        }
    }

    // Now expand the current NonTerminal
    token *start = posToken;
    // Now pick the rule corresponding to the given NonTerminal

    grules *exp = G[p->Node.nonTerminal.nt].head;
    int found = 0;
    while (exp != NULL) // picking a partcular rule
    {
        //printf("The Rule Selected Now is: %s--> \n", NonTerminalMap[p->Node.nonTerminal.nt]);
        // Now traverse over the elements of the rule selected
        int ans = 1;
        rule *curr = exp->head;
        parseTree *prevChild = NULL;
        while (curr != NULL) // a particular element of the rule
        {
            //create The Node
            if (curr->isterm)
            {
                //printf(" %s ", TerminalMap[curr->type.t]);
            }
            else
            {
                //printf("< %s >", NonTerminalMap[curr->type.nt]);
            }
            parseTree *child = createTreeNode(curr, p);
            if (curr->isterm)
            {
                child->Node.terminal.line_num = posToken->lineno;
                strcpy(child->Node.terminal.lexeme, posToken->lexeme);
            }

            // Add to the first child of parent if prevChild is NULL
            if (prevChild == NULL)
                p->firstChild = child;
            else
                prevChild->sibling = child;

            prevChild = child;

            if (!createParseTree(child, G)) // cannot add this child
            {
                //printf("ERROR\n");
                ans = 0;
                break;
            }

            // move to the next rule as previous place
            curr = curr->next;
        }
        if (ans)
        {
            //printf("DONE\n");
            found = 1;
            break;
        }
        else
        {
            // backTracking Step
            // Revert the changes made
            // func for deleting the child nodes
            posToken = start;

            // delete all the childs of p ... starting from firstChild
            parseTree *child = p->firstChild;

            while (child != NULL)
            {
                parseTree *nextChild = child->sibling;
                // delete the subtree corresponding to this node
                deleteSubtree(child);
                child = nextChild;
            }
        }
        exp = exp->next;
    }
    if (!found)
    {
        // The non terminal which came cannot be expanded
        return NULL;
    }
    // PRINTING
    //printf("NON TERMINAL-->%s \n", NonTerminalMap[p->Node.nonTerminal.nt]);

    p->Node.nonTerminal.expRule = exp;
    return p; // return the node itself
}

/*PRINT PARSE TREE FUNC*/

// Symbol name
// Whether terminal or non terminal
// Type expression stored in the corresponding node (if non-leaf)
// Name of lexeme (if leaf node)
// Line number (if leaf node)
// Grammar rule applied for expansion of this node while parsing (if non leaf)
// Depth of node (root of the parse tree at depth 0)

void printRule(grules *expRule, NonTerminal nt, FILE *fp)
{
<<<<<<< HEAD
    char buff[200] = "\0";
    strcat(buff, NonTerminalMap[nt]);
    strcat(buff, " =>");
    //fprintf(fp, "%s => ", NonTerminalMap[nt]);
    rule *curr = expRule->head;

    while (curr != NULL)
    {
        // print the rule
        if (curr->isterm)
        {
            //fprintf(fp, " %s", TerminalMap[curr->type.t]);
            strcat(buff, " ");
            strcat(buff, TerminalMap[curr->type.t]);
        }
        else
        {
            //fprintf(fp, " <%s>", NonTerminalMap[curr->type.nt]);
            strcat(buff, " <");
            strcat(buff, NonTerminalMap[curr->type.nt]);
            strcat(buff, ">");
        }
        curr = curr->next;
    }
    fprintf(fp, "%-200s", buff);
=======
	char buff[200] = "\0";
	strcat(buff, NonTerminalMap[nt]);
	strcat(buff, " =>");
	//fprintf(fp, "%s => ", NonTerminalMap[nt]);
	rule * curr = expRule->head;
	
	while(curr != NULL)
	{
		// print the rule
		if(curr->isterm)
		{
			//fprintf(fp, " %s", TerminalMap[curr->type.t]);
			strcat(buff, " ");
			strcat(buff, TerminalMap[curr->type.t]);
		}
		else
		{
			//fprintf(fp, " <%s>", NonTerminalMap[curr->type.nt]);
			strcat(buff, " <");
			strcat(buff, NonTerminalMap[curr->type.nt]);
			strcat(buff, ">");
		}
		curr = curr->next;
	}
	fprintf(fp, "%-200s", buff);
>>>>>>> b5201d7a1fdbe88476c185ec4c82aa191e8e0159
}

void printParseTreeUtil(parseTree *t, FILE *fp, int depth)
{
<<<<<<< HEAD
    if (t == NULL)
        return;
    // print here the node and call the function for the children
    if (t->isTerm)
    {
        char *ter = "TERMINAL";
        fprintf(fp, "%-25s", TerminalMap[t->Node.terminal.t]); // print the symbol
        fprintf(fp, "%-25s", ter);
        fprintf(fp, "%-300s", "NULL");
        fprintf(fp, "%-35s", t->Node.terminal.lexeme);
        fprintf(fp, "%-10d", t->Node.terminal.line_num);
        fprintf(fp, "%-250s", "NULL");
        fprintf(fp, "%-10d\n", depth);
    }

    else
    {

        char *ter = "NON TERMINAL";
        fprintf(fp, "%-25s", NonTerminalMap[t->Node.nonTerminal.nt]); // print the symbol
        fprintf(fp, "%-25s", ter);
        if (t->exp_type.tag == not_app)
        {
            fprintf(fp, "%-300s", "--Ignored--");
        }
        else
        {
            if (t->exp_type.tag == primitive)
            { //Primitive
                fprintf(fp, "<basicType=%s>%-200s", TerminalMap[t->exp_type.record.primitive_type], "");
            }
            else if (t->exp_type.tag == array)
            {
                int dim = t->exp_type.record.arr_record.dim;
                fprintf(fp, " <type=rectangularArray, dimensions=%d, ", dim);

                for (int j = 0; j < dim; j++)
                {
                    int a = t->exp_type.record.arr_record.dim_bound[j][0];
                    int b = t->exp_type.record.arr_record.dim_bound[j][1];
                    // printf("%s\n",t->exp_type.record.arr_record.l_indexes[0]);
                    //case for var_name in d_bind
                    if (a != -1 && b != -1)
                        fprintf(fp, "range_R%d= (%d, %d), ", j + 1, a, b);
                    else if (a == -1 && b != -1)
                        fprintf(fp, "range_R%d= (%s, %d), ", j + 1, t->exp_type.record.arr_record.l_indexes[j], b);
                    else if (a != -1 && b == -1)
                        fprintf(fp, "range_R%d= (%d, %s), ", j + 1, a, t->exp_type.record.arr_record.u_indexes[j]);
                    else if (a == -1 && b == -1)
                        fprintf(fp, "range_R%d= (%s, %s), ", j + 1, t->exp_type.record.arr_record.l_indexes[j], t->exp_type.record.arr_record.u_indexes[j]);
                }
                fprintf(fp, "basicElementType = Integer>%-110s", "");
            }
            else if (t->exp_type.tag == jagged_array)
            { //Jagged_ARRAY
                int dim = t->exp_type.record.j_arr_record.dim;

                fprintf(fp, " <type =jaggedArray, dimensions=%d, ", dim);

                if (dim == 2)
                {
                    int high = t->exp_type.record.j_arr_record.r1_high;
                    int low = t->exp_type.record.j_arr_record.r1_low;
                    fprintf(fp, "range_R1=(%d, %d) range_R2 = (", low, high);

                    for (int j = 0; j < high - low + 1; j++)
                    {
                        fprintf(fp, " %d ", t->exp_type.record.j_arr_record.dim_bound._line[j]);
                        if (j != high - low)
                            fprintf(fp, ",");
                        //from (low,high) gives size  , 0 index
                    }
                }
                else
                { //dim==3
                    int high = t->exp_type.record.j_arr_record.r1_high;
                    int low = t->exp_type.record.j_arr_record.r1_low;
                    fprintf(fp, "range_R1=(%d, %d) range_R2 = ( ", low, high);
                    //  <type =jaggedArray, dimensions=3, range_R1=(4, 7),
                    //3 [ 5, 3, 5] ,
                    //1 [  5], 2 [ 4, 3] ,3 [ 5, 4, 4]
                    for (int j = 0; j < high - low + 1; j++)
                    {
                        int m = t->exp_type.record.j_arr_record.dim_bound.jag_line[j][0];
                        fprintf(fp, "%d [", m);
                        for (int k = 0; k < m; k++)
                        {
                            fprintf(fp, " %d", t->exp_type.record.j_arr_record.dim_bound.jag_line[j][k + 1]);
                            if (k != m - 1)
                                fprintf(fp, ",");
                        }
                        fprintf(fp, " ]");
                        if (j != high - low)
                            fprintf(fp, ", ");
=======
	if(t == NULL) return;
	// print here the node and call the function for the children
	if(t->isTerm)
	{
		char * ter = "TERMINAL";
			fprintf(fp, "%-25s", TerminalMap[t->Node.terminal.t] ); // print the symbol
			fprintf(fp, "%-25s", ter);
			fprintf(fp, "%-300s", "NULL");
			fprintf(fp, "%-35s", t->Node.terminal.lexeme);
			fprintf(fp, "%-10d", t->Node.terminal.line_num);
			fprintf(fp, "%-250s", "NULL");
			fprintf(fp, "%-10d\n", depth);
	}

	else
	{
        
		char * ter = "NON TERMINAL";
			fprintf(fp, "%-25s", NonTerminalMap[t->Node.nonTerminal.nt] ); // print the symbol
			fprintf(fp, "%-25s", ter);
			if(t->exp_type.tag==not_app){
                fprintf(fp, "%-300s", "--Ignored--");
            }
            else{
                if(t->exp_type.tag==primitive){ //Primitive
                fprintf(fp,"<basicType=%s>%-200s",TerminalMap[t->exp_type.record.primitive_type],"");
                }  
                else if(t->exp_type.tag==array){
                     int dim=t->exp_type.record.arr_record.dim;
                     fprintf(fp," <type=rectangularArray, dimensions=%d, " ,dim);
            
                    for(int j=0;j<dim;j++){
                            int a= t->exp_type.record.arr_record.dim_bound[j][0];
                            int b= t->exp_type.record.arr_record.dim_bound[j][1];
                           // printf("%s\n",t->exp_type.record.arr_record.l_indexes[0]);
                            //case for var_name in d_bind
                            if(a!=-1&&b!=-1)fprintf(fp,"range_R%d= (%d, %d), ",j+1,a,b);
                            else if(a==-1&&b!=-1)fprintf(fp,"range_R%d= (%s, %d), ",j+1,t->exp_type.record.arr_record.l_indexes[j],b);
                            else if(a!=-1&&b==-1)fprintf(fp,"range_R%d= (%d, %s), ",j+1,a,t->exp_type.record.arr_record.u_indexes[j]);
                            else if(a==-1&&b==-1)fprintf(fp,"range_R%d= (%s, %s), ",j+1,t->exp_type.record.arr_record.l_indexes[j],t->exp_type.record.arr_record.u_indexes[j]);
                            
                         }
                            fprintf(fp,"basicElementType = Integer>%-110s","");
                      }
                else if(t->exp_type.tag==jagged_array){    //Jagged_ARRAY
                    int dim=t->exp_type.record.j_arr_record.dim;
                    
                    fprintf(fp," <type =jaggedArray, dimensions=%d, ",dim);
                
                    if(dim==2){
                            int  high=t->exp_type.record.j_arr_record.r1_high;
                            int low=t->exp_type.record.j_arr_record.r1_low   ;
                            fprintf(fp,"range_R1=(%d, %d) range_R2 = (",low,high);
                                
                            for(int j=0;j<high-low+1;j++){
                                fprintf(fp," %d ",t->exp_type.record.j_arr_record.dim_bound._line[j]);
                                if(j!=high-low)fprintf(fp,",");
                                //from (low,high) gives size  , 0 index 
                            }
                            
>>>>>>> b5201d7a1fdbe88476c185ec4c82aa191e8e0159
                    }
                }
                fprintf(fp, "), basicElementType = integeri> %-10s", "ji");

                //basic=Integer by def
            }
<<<<<<< HEAD
=======
            fprintf(fp,"), basicElementType = integeri> %-10s","ji");
           
       //basic=Integer by def
        }
>>>>>>> b5201d7a1fdbe88476c185ec4c82aa191e8e0159
        }

        // print the tyeExpression

<<<<<<< HEAD
        fprintf(fp, "%-35s", "NULL");
        fprintf(fp, "%-10s", "NULL");
        //fprintf(fp, "%-100s", "NULL"); // print The rule here
        printRule(t->Node.nonTerminal.expRule, t->Node.nonTerminal.nt, fp);
        fprintf(fp, "%-10d\n", depth);
    }

    parseTree *child = t->firstChild;

    while (child != NULL)
    {
        printParseTreeUtil(child, fp, depth + 1);
        child = child->sibling;
=======
			fprintf(fp, "%-35s", "NULL");
			fprintf(fp, "%-10s", "NULL");
			//fprintf(fp, "%-100s", "NULL"); // print The rule here
			printRule(t->Node.nonTerminal.expRule, t->Node.nonTerminal.nt, fp);
			fprintf(fp, "%-10d\n", depth);
>>>>>>> b5201d7a1fdbe88476c185ec4c82aa191e8e0159
    }
}

void printParseTree(parseTree *t)
{
<<<<<<< HEAD
    // Initial setup.
    FILE *fp = fopen("parseTree.txt", "w");

    fprintf(fp, "\n------------------------------------------------------Printing Parse Tree-----------------------------------------------------\n\n");
    //printf("\n------------------------------------------------------Printing Parse Tree On the Console-----------------------------------------------\n\n");
    //fprintf(fp, "HELLO\n\n");
    //fprintf(fp, "%-25s %-10s %-15s %-15s %-30s %-5s %s\n\n\n", "LEXEME","LINE","TOKEN","VALUE","PARENT","LEAF","NODE");
    fprintf(fp, "%-24s %-25s %-300s %-30s %-10s %-200s %-10s\n\n\n", "SYMBOL", "TERMINAL / NON TERMINAL", "TYPE EXPRESSION", "LEXEME", "LINE", "GRAMMAR RULE", "DEPTH");

    printParseTreeUtil(t, fp, 0);

    fprintf(fp, "\n------------------------------------------------------Parse Tree Printed On the FILE-----------------------------------------------\n\n");
    fclose(fp);
}

int CAPACITY = 0;
int m = 0;

// FUNCTION FOR JAG LINE CHECKING//

TypeExpression jagged(int lo, int hi, parseTree *jagLines, int dimen, TypeExpression expr)
{
    //printf("%s\n", NonTerminalMap[jagLines->Node.nonTerminal.nt]);
    //printf("5d\n");
    expr.record.j_arr_record.dim = dimen;
    expr.record.j_arr_record.r1_high = hi;
    expr.record.j_arr_record.r1_low = lo;
    int indx = 0;     // To RECORD INDEX
    int szchk = lo;   // TO CHECK INDEX
    int sz = 0;       // TO RECORD SIZE IN EACH JAGLINE
    int numcount = 0; // TO TRACK SIZE
    int idxcount = 0; // For Jagged_3d_array to track no. of elemets in 3rd dimension
    int *line = NULL;
    int **jagl = NULL;
    parseTree *dpnumList = NULL;
    if (dimen == 2)
    {
        line = (int *)malloc(sizeof(int) * (hi - lo + 1));
    }
    else
    {
        //printf("5jd\n");
        jagl = (int **)malloc(sizeof(int *) * (hi - lo + 1));
    }

    parseTree *jagLine = jagLines->firstChild; //Pointing to a Jagline
    //printf("%s\n", NonTerminalMap[jagLine->Node.nonTerminal.nt]);
    do
    {
        //printf("5dijfgfg lololllo\n");
        //printf("%s\n", NonTerminalMap[jagLine->Node.nonTerminal.nt]);
        parseTree *jagList = jagLine->firstChild->sibling->sibling; //Pointing to Num like R1[NUM]
        //printf("%s\n", TerminalMap[jagList->Node.terminal.t]);
        //printf("5dijfgfg\n");
        indx = atoi(jagList->Node.terminal.lexeme);
        //printf("% d \n", indx);
        if (szchk != indx) // Checking index value
        {
            int dep = 0;
            if (dimen == 2)
            {
                printf("%d   DECLARATION   ***   ***   ***   ***   ***   %d   2D_Jagged_Array_Index_Mismatch \n", jagList->Node.terminal.line_num, dep);
            }
            else
            {
                printf("%d   DECLARATION   ***   ***   ***   ***   ***   %d   3D_Jagged_Array_Index_Mismatch \n", jagList->Node.terminal.line_num, dep);
            }

            //error IF R1[VALUE] IS CORRECT OR NOT
            //printf("in break\n");
            expr.tag = not_app;
            return expr;
        }
        szchk++;
        //printf("5dij\n");
        jagList = jagList->sibling->sibling->sibling->sibling; // Pointing to next Num sixe(NUM)
        sz = atoi(jagList->Node.terminal.lexeme);              //Receiving the size of the array
        jagList = jagList->sibling->sibling->sibling->sibling; // Pointing to REAL JagList
        parseTree *numList = jagList->firstChild;              // Pointing to a numlist of rule <jag_list> => <num_list> SEMICOLON <jag_list> ||  <num_list> || EPSILON
        //printf("%s thththth\n", NonTerminalMap[numList->Node.nonTerminal.nt]);
        //printf("5dij\n");
        if (dimen == 2)
        {
            if (jagList->Node.terminal.t == EPSILON)
            {
                printf("JJJJ\n");
            }
            while (numList->sibling != NULL)
            {
                dpnumList = numList->firstChild;                                     // Pointing to NUM or EPSILON of rule <num_list> => NUM <num_list> || NUM || EPSILON
                if (dpnumList->Node.terminal.t == NUM && dpnumList->sibling == NULL) // Not more than two in a numList and single NUM to be present b/w semicolons
                {
                    numcount++;
                }
                else if (dpnumList->sibling != NULL)
                {
                    printf("%s\n", NonTerminalMap[dpnumList->sibling->Node.nonTerminal.nt]);
                    printf("%s\n", TerminalMap[dpnumList->sibling->firstChild->Node.nonTerminal.nt]);
                    int dep = 0;
                    printf("YY\n");
                    printf("%d   DECLARATION   ***   ***   ***   ***   ***   %d   2D_Jagged_Array_Multiple_Element_In_Row \n", dpnumList->Node.terminal.line_num, dep);
                    expr.tag = not_app;
                    return expr;
                    // Like 3d array
                    //error
                }
                else if (dpnumList->Node.terminal.t == EPSILON)
                {
                    // int dep = 0;
                    // printf("%d   DECLARATION   ***   ***   ***   ***   ***   %d   2D_Jagged_Array_No_Element_In_Row \n", dpnumList->Node.terminal.line_num, dep);
                    // expr.tag = not_app;
                    // return expr;
                    //error Empty
                }
                numList = numList->sibling->sibling->firstChild;
                //numList=numList->firstChild->sibling; // Moving to next numList
            }
            if (numList->firstChild->Node.terminal.t == EPSILON) //EPSILON IN LAST
            {
                //error Last element is EPSILON
            }
            else if (numList->firstChild->sibling != NULL)
            {

                int dep = 0;
                printf("%d   DECLARATION   ***   ***   ***   ***   ***   %d   2D_Jagged_Array_Multiple_Element_In_Row \n", numList->firstChild->Node.terminal.line_num, dep);
                expr.tag = not_app;
                return expr;
                // Like 3d array
                //error
            }
            numcount++;
            if (sz != numcount) // Matchng size with no. of elements counted
            {
                //error No. of elements do not match size
            }
            line[szchk - lo - 1] = sz;
        }
        else
        {
            //printf("5d3d\n");
            int counter = 1;
            //printf("%d %d \n\n", szchk, lo);
            jagl[szchk - lo - 1] = (int *)malloc(sizeof(int) * (sz + 1));
            jagl[szchk - lo - 1][0] = sz;
            while (numList->sibling != NULL) // Pointing to a numlist of rule <jag_list> => <num_list> SEMICOLON <jag_list> ||  <num_list>
            {
                //printf("HELELELEl\n");
                idxcount = 0;
                //printf("%s thththth\n", NonTerminalMap[numList->Node.nonTerminal.nt]);
                dpnumList = numList->firstChild; // Pointing to NUM of rule <num_list> => NUM <num_list> || NUM
                //printf("%s thththlklklklk\n", dpnumList->Node.terminal.lexeme);
                while (dpnumList->sibling != NULL) // TRAVERSING THE RULE to eat all NUM in <num_list>
                {
                    idxcount++;
                    dpnumList = dpnumList->sibling->firstChild;
                    //printf("%s \n", dpnumList->Node.terminal.lexeme);
                }
                if (dpnumList->Node.terminal.t == EPSILON)
                {
                    // error EPSILON ENCOUNTERED
                }
                idxcount++;
                jagl[szchk - lo - 1][counter] = idxcount;
                //printf("%d idxid\n", idxcount);
                counter++;
                numList = numList->sibling->sibling->firstChild;
            }
            //printf("HSAHILSAHIKl\n");
            idxcount = 0;
            dpnumList = numList->firstChild;
            //printf("%s \n", dpnumList->Node.terminal.lexeme);
            while (dpnumList->sibling != NULL) // TRAVERSING THE RULE to eat all NUM in <num_list>
            {
                idxcount++;
                dpnumList = dpnumList->sibling->firstChild;
                //printf("%s raj\n", dpnumList->Node.terminal.lexeme);
            }
            if (dpnumList->Node.terminal.t == EPSILON)
            {
                // error EPSILON ENCOUNTERED
            }
            idxcount++;
            //printf("%d mmnmnmn\n", idxcount);
            jagl[szchk - lo - 1][counter] = idxcount;
            if (counter != sz)
            {
                //error Size don't match
            }
        }
        if (jagLine->sibling == NULL)
        {
            //printf("ijhgrsihjgs\n");
            jagLine = jagLine->sibling;
        }
        else
        {
            jagLine = jagLine->sibling->firstChild; // Move to next Jagline after Traversing a single Jagline
        }

    } while (jagLine != NULL);
    if (dimen == 2)
    {
        expr.record.j_arr_record.dim_bound._line = line;
    }
    else
    {
        expr.record.j_arr_record.dim_bound.jag_line = jagl;
    }
    return expr;
=======
	// Initial setup.
	FILE* fp = fopen("parseTree.txt", "w");

	fprintf(fp,"\n------------------------------------------------------Printing Parse Tree-----------------------------------------------------\n\n");
	//printf("\n------------------------------------------------------Printing Parse Tree On the Console-----------------------------------------------\n\n");
	//fprintf(fp, "HELLO\n\n");
	//fprintf(fp, "%-25s %-10s %-15s %-15s %-30s %-5s %s\n\n\n", "LEXEME","LINE","TOKEN","VALUE","PARENT","LEAF","NODE");
	fprintf(fp,"%-24s %-25s %-300s %-30s %-10s %-200s %-10s\n\n\n", "SYMBOL","TERMINAL / NON TERMINAL","TYPE EXPRESSION", "LEXEME","LINE","GRAMMAR RULE", "DEPTH");

	printParseTreeUtil(t,fp, 0);
	
	
	fprintf(fp,"\n------------------------------------------------------Parse Tree Printed On the FILE-----------------------------------------------\n\n");
	fclose(fp);
>>>>>>> b5201d7a1fdbe88476c185ec4c82aa191e8e0159
}

TypeExpressionTable *table;
void append_to_table(TypeExpression type, char *var)
{
    if (CAPACITY == 0)
    {

        table = (TypeExpressionTable *)malloc(sizeof(TypeExpressionTable) * 10);
        CAPACITY = 10;
    }
    else if (m == CAPACITY)
    {
        //  printf("yahani %d %s \n",m,var);
        table = (TypeExpressionTable *)realloc(table, sizeof(TypeExpressionTable) * CAPACITY * 2);
        CAPACITY = CAPACITY * 2;
    }

    //printf("yahani %d %d %s \n",m,CAPACITY,var);
    strcpy(table[m].var_name, var);

    table[m].tag = type.tag;
    table[m].info = type.info;
    table[m].record = type.record;

    m++;

    return;
}

void traverse_parse_tree(parseTree *t)
{
    //   printf("here\n");
    if (t->isTerm == 0 && t->Node.nonTerminal.nt == s)
    {
        t = t->firstChild->sibling->sibling->sibling->sibling;
        traverse_parse_tree(t);
        //pointer t is pointing/moving to <start>
        return;
    }
    //pointer t is pointing/moving to <start>
    else if (t->isTerm == 0 && t->Node.nonTerminal.nt == start)
    {
        traverse_parse_tree(t->firstChild);
        traverse_parse_tree(t->firstChild->sibling);
        return;
    }

    else if (t->isTerm == 0 && t->Node.nonTerminal.nt == declaration)
    {
        traverse_parse_tree(t->firstChild); //to dec_stmnt
        if (t->firstChild->sibling != NULL)
        {
            traverse_parse_tree(t->firstChild->sibling); //to declarations or null
        }
        return;
    }
    else if (t->isTerm == 0 && t->Node.nonTerminal.nt == declaration_stmt)
    {
        //build for the "typeExpression" of this declarartion statement, error reporting
        TypeExpression exp_table_record;
        parseTree *varlist_pointer = NULL;
        parseTree *temp = t; //just being safe, making copy
        temp = temp->firstChild;

        if (temp->isTerm == 0 && temp->Node.nonTerminal.nt == primitive)
        {
            ///    printf("herein\n");
            exp_table_record.tag = primitive; //primitive/jagged_array/array//terminal
            exp_table_record.info = N_A;
            temp = temp->firstChild; //pointing to var_list  //moving into single/multiple_primitive node //populate type expressions
            if (temp->isTerm == 0 && temp->Node.nonTerminal.nt == single_primitive)
            {
                varlist_pointer = temp = temp->firstChild->sibling;
                temp = temp->sibling->sibling; //moving into colon ke baad wala node
            }
            else
            { //multiple
                varlist_pointer = temp = temp->firstChild->sibling->sibling->sibling->sibling;
                temp = temp->sibling->sibling; //moving into colon ke baad wala node
            }
            //
            exp_table_record.record.primitive_type = temp->firstChild->Node.terminal.t; //INT/BOOl/REAL(terminal)
            //daalnaa
            //storing to <single_primitive> and <primitive>
            temp->parent->exp_type = exp_table_record;
            temp->parent->parent->exp_type = exp_table_record;
        }
        else if (temp->isTerm == 0 && temp->Node.nonTerminal.nt == array)
        {
            exp_table_record.tag = array;
            exp_table_record.info = Static;
            temp = temp->firstChild;

            int line = temp->firstChild->Node.terminal.line_num;
            if (temp->isTerm == 0 && temp->Node.nonTerminal.nt == single_array)
            {
                varlist_pointer = temp = temp->firstChild->sibling;
                temp = temp->sibling->sibling; //moving into colon ke baad wala node
            }
            else
            {
                varlist_pointer = temp = temp->firstChild->sibling->sibling->sibling->sibling;
                temp = temp->sibling->sibling; //moving into colon ke baad wala node
            }

            temp = temp->sibling; //(ignore just after colon, arrray written)

            //<array_dim> hai aab, in temp
            parseTree *store = temp; //at <array_dim>

            int count = 0;
            int strcount = 0;
            int strcount2 = 0;
            int r1 = -1, r2 = -1;
            int **tem = (int **)malloc(2 * sizeof(int *));
            int s_g = 1;
            int s_g2 = 1;
            char **l_indexes = (char **)malloc(sizeof(char *));
            char **u_indexes = (char **)malloc(sizeof(char *));

            // int strCount=0;
            // char **indexes;
            int g = 1, b = 2;
            //char ** indexes = (char **)malloc(sizeof(char *));

            do
            {

                temp = temp->firstChild; //(moving into the child of  <array_dim>)
                temp = temp->sibling;

                //id or num =temp->firstChild;

                if (temp->firstChild->Node.terminal.t == ID) //checking if dimension is ID.
                {
                    exp_table_record.info = Dynamic;
                    r1 = -1;
                }
                else
                { // If dimension is NUM
                    r1 = atoi(temp->firstChild->Node.terminal.lexeme);
                    if (r1 == -1)
                        r1 = -100;
                }

                //
                if (r1 == -1)
                {
                    if (strcount >= s_g)
                    {
                        l_indexes = (char **)realloc(l_indexes, (s_g * 2) * sizeof(char *));
                        s_g = s_g * 2;
                    }
                    // printf("here\n");
                    int len = strlen(temp->firstChild->Node.terminal.lexeme);
                    l_indexes[strcount] = (char *)malloc(len * sizeof(char)); //allocating space to store left and right index
                    strcpy(l_indexes[strcount], temp->firstChild->Node.terminal.lexeme);
                    // Storing ID in form of string
                    //printf("l-> %s  :  %s %d\n",temp->firstChild->Node.terminal.lexeme,l_indexes[strcount],strcount );
                    strcount++;
                }
                else
                {
                    if (strcount >= s_g)
                    {
                        l_indexes = (char **)realloc(l_indexes, (s_g * 2) * sizeof(char *));
                        s_g = s_g * 2;
                    }
                    int len = 12;
                    l_indexes[strcount] = (char *)malloc(len * sizeof(char)); //allocating space to store left and right index
                    strcpy(l_indexes[strcount], "NumericValue");
                    // Storing ID in form of string
                    // printf("l-> %s %s %d\n",temp->firstChild->Node.terminal.lexeme,l_indexes[strcount],strcount );
                    strcount++;
                }

                temp = temp->sibling->sibling; //ignoring .. (DD)

                if (temp->firstChild->Node.terminal.t == ID) // checking if dimension is ID
                {
                    exp_table_record.info = Dynamic;

                    r2 = -1;
                }
                else
                { // If dimension is NUM
                    r2 = atoi(temp->firstChild->Node.terminal.lexeme);
                    if (r2 == -1)
                        r2 = -100;
                }
                if (r2 == -1)
                {
                    // printf("here2\n");
                    if (strcount2 >= s_g2)
                    {
                        u_indexes = (char **)realloc(u_indexes, (s_g2 * 2) * sizeof(char *));
                        s_g2 = s_g2 * 2;
                    }
                    int len = strlen(temp->firstChild->Node.terminal.lexeme);
                    u_indexes[strcount2] = (char *)malloc(len * sizeof(char)); //allocating space to store left and right index
                    strcpy(u_indexes[strcount2], temp->firstChild->Node.terminal.lexeme);
                    // Storing ID in form of string
                    // printf("u-> %s : %s %d\n",temp->firstChild->Node.terminal.lexeme,u_indexes[strcount2],strcount2 );
                    strcount2++;
                }
                else
                {
                    // printf("here2\n");
                    if (strcount2 >= s_g2)
                    {
                        // printf("here2\n");
                        u_indexes = (char **)realloc(u_indexes, (s_g2 * 2) * sizeof(char *));
                        s_g2 = s_g2 * 2;
                    }
                    int len = 12;
                    u_indexes[strcount2] = (char *)malloc(len * sizeof(char)); //allocating space to store left and right index
                    strcpy(u_indexes[strcount2], "NumericValue");
                    //printf("u -> %s %s %d\n",temp->firstChild->Node.terminal.lexeme,u_indexes[strcount2],strcount2 );
                    //Storing ID in form of string
                    strcount2++;
                }

                temp = temp->sibling->sibling; //reaches <array_dim>

                //chk type(dynamic), dimension(lower<upper), read, and error report, maintain counter for Dimension Count, dimension=count;
                //store to type_Expression_record.record.arr_record;
                if ((r1 == -1 && r2 >= 0) || (r1 >= 0 && r2 == -1) || (r1 >= 0 && r2 >= 0 && r1 <= r2) || (r1 == -1 && r2 == -1)) //(-1 for ID)
                //checking if lower_index < higher_index and ignore if one (or both) index are ID and NUM should be >= 0
                {
                    count++;
                    exp_table_record.record.arr_record.dim = count;
                    if (count > g * b)
                    {
                        tem = (int **)realloc(tem, 2 * (count - 1) * sizeof(int *));
                        g++;
                    }
                    tem[count - 1] = (int *)malloc(2 * sizeof(int)); //allocating space to store left and right index
                    tem[count - 1][0] = r1;
                    tem[count - 1][1] = r2;
                    exp_table_record.record.arr_record.dim_bound = tem;
                    exp_table_record.record.arr_record.l_indexes = l_indexes;
                    exp_table_record.record.arr_record.u_indexes = u_indexes;

                    store->parent->exp_type = exp_table_record;
                    store->parent->parent->exp_type = exp_table_record;
                }
                else //if lower_range becomes greater than higher_range
                {
                    exp_table_record.tag = not_app;
                    exp_table_record.info = N_A; //erroneous type declaration, storing N_A in the field in node.

                    int dep = 0;
                    printf("%d   DECLARATION   ***   ***   ***   ***   ***   %d   Array_Range_Mismatch \n", line, dep);
                    break;
                }

            } while (temp != NULL);
            //storing to single_array and array

            //temp2=daalde
        }

        //**********JAGGED ARRAY**********************//

        else if (temp->isTerm == 0 && temp->Node.nonTerminal.nt == jagged_array)
        {
            //printf("Hell\n");
            temp = temp->firstChild; //jagged_2d_array or jagged_3d_array
            if (temp->isTerm == 0 && temp->Node.nonTerminal.nt == jagged_2d_array)
            {
                exp_table_record.tag = jagged_array;
                exp_table_record.info = N_A;
                temp = temp->firstChild; //single_jagged_2d or multi_jagged_2d
                //printf("%s nn\n", NonTerminalMap[temp->Node.nonTerminal.nt]);
                if (temp->isTerm == 0 && temp->Node.nonTerminal.nt == single_jagged_2d_array)
                {
                    varlist_pointer = temp = temp->firstChild->sibling;
                    temp = temp->sibling->sibling; //moving into colon ke baad wala node
                }
                else
                {
                    varlist_pointer = temp = temp->firstChild->sibling->sibling->sibling->sibling;
                    temp = temp->sibling->sibling; //moving into colon ke baad wala node
                }
                temp = temp->sibling->sibling; //(ignore just after colon, jagged and arrray written)
                //<jagged_2d_dim> hai , in temp
                parseTree *store = temp;                                             //at <jagged_2d_dim>
                int l_bound = atoi(temp->firstChild->sibling->Node.terminal.lexeme); //at NUM
                int u_bound = atoi(temp->firstChild->sibling->sibling->sibling->Node.terminal.lexeme);
                int dimension = 2;
                //temp <jagged_2d_dim> pe hi hai
                if (l_bound <= u_bound)
                { //chk =
                    //traverse for jaglines
                    temp = temp->sibling->sibling->sibling->sibling; //reach <jag_lines>
                    exp_table_record = jagged(l_bound, u_bound, temp, dimension, exp_table_record);
                }
                else
                {
                    //error
                    int dep = 0;
                    printf("%d   DECLARATION   ***   ***   ***   ***   ***   %d   Jagged_Array_Range_Mismatch \n", temp->firstChild->sibling->Node.terminal.line_num, dep);
                    exp_table_record.tag = not_app;
                }
                store->parent->exp_type = exp_table_record;
                store->parent->parent->exp_type = exp_table_record;
                store->parent->parent->parent->exp_type = exp_table_record;
            }
            else if (temp->isTerm == 0 && temp->Node.nonTerminal.nt == jagged_3d_array)
            {
                //printf("%s nh\n", NonTerminalMap[temp->Node.nonTerminal.nt]);
                exp_table_record.tag = jagged_array;
                exp_table_record.info = N_A;
                //printf("3d\n");
                temp = temp->firstChild;
                //printf("%s nn\n", NonTerminalMap[temp->Node.nonTerminal.nt]);
                if (temp->isTerm == 0 && temp->Node.nonTerminal.nt == single_jagged_3d_array)
                {
                    varlist_pointer = temp = temp->firstChild->sibling;
                    temp = temp->sibling->sibling; //moving into colon ke baad wala node
                }
                else
                {
                    //printf("3d\n");
                    varlist_pointer = temp = temp->firstChild->sibling->sibling->sibling->sibling;
                    temp = temp->sibling->sibling; //moving into colon ke baad wala node
                }
                temp = temp->sibling->sibling; //(ignore just after colon, jagged and arrray written)
                //printf("%s hhhnlllll\n", NonTerminalMap[temp->Node.nonTerminal.nt]); //<jagged_3d_dim> hai , in temp
                parseTree *store = temp; //at <jagged_2d/3d_dim>
                int l_bound = atoi(temp->firstChild->sibling->Node.terminal.lexeme);
                int u_bound = atoi(temp->firstChild->sibling->sibling->sibling->Node.terminal.lexeme);
                //printf("%d %d", l_bound, u_bound);
                int dimension = 3;
                if (l_bound <= u_bound)
                { //chk =
                    //kamm alag hoga.
                    //printf("%s hhhnyyyy\n", NonTerminalMap[temp->sibling->sibling->sibling->sibling->Node.nonTerminal.nt]);
                    exp_table_record = jagged(l_bound, u_bound, temp->sibling->sibling->sibling->sibling, dimension, exp_table_record);
                    //printf("4d\n");
                }
                else
                {
                    int dep = 0;
                    printf("%d   DECLARATION   ***   ***   ***   ***   ***   %d   Jagged_Array_Range_Mismatch \n", temp->firstChild->sibling->Node.terminal.line_num, dep);
                    //error
                }
                store->parent->exp_type = exp_table_record;
                store->parent->parent->exp_type = exp_table_record;
                store->parent->parent->parent->exp_type = exp_table_record;
            }
        }

        if (varlist_pointer != NULL) // SAFETY CHECK
        {
            if (varlist_pointer->isTerm == 1 && varlist_pointer->Node.terminal.t == ID)
            {
                // printf("yaha\n");
                varlist_pointer->exp_type = exp_table_record;
                //   printf("%d\n\n\n",varlist_pointer->exp_type.tag);
                //append to typeExpression Table

                append_to_table(exp_table_record, varlist_pointer->Node.terminal.lexeme);
            }
            else
            {
                //traverse all IDs
                //printf("yaha\n");
                do
                {
                    //    printf("yahan\n");
                    varlist_pointer->exp_type = exp_table_record;
                    varlist_pointer = varlist_pointer->firstChild;

                    varlist_pointer->exp_type = exp_table_record;

                    //append to typeExpression Table
                    append_to_table(exp_table_record, varlist_pointer->Node.terminal.lexeme);

                    varlist_pointer = varlist_pointer->sibling;

                } while (varlist_pointer != NULL);
            }
        }
        return;
<<<<<<< HEAD
    }

    /*********/ //RAJAT/************/

    else if (t->isTerm == 0 && t->Node.nonTerminal.nt == assignment)
    {
=======
   }
   else if(t->isTerm==0&&t->Node.nonTerminal.nt==declaration_stmt){
       //build for the "typeExpression" of this declarartion statement, error reporting
       TypeExpression exp_table_record;
        parseTree* varlist_pointer=NULL; 
       parseTree * temp=t;    //just being safe, making copy
       temp=temp->firstChild;

       if(temp->isTerm==0&&temp->Node.nonTerminal.nt==primitive){
       ///    printf("herein\n");
           exp_table_record.tag=primitive;          //primitive/jagged_array/array//terminal
           exp_table_record.info=N_A;
           temp=temp->firstChild;   //pointing to var_list  //moving into single/multiple_primitive node //populate type expressions
           if(temp->isTerm==0&&temp->Node.nonTerminal.nt==single_primitive){
               varlist_pointer=temp=temp->firstChild->sibling;
               temp=temp->sibling->sibling;//moving into colon ke baad wala node
           }
           else{//multiple
               varlist_pointer=temp=temp->firstChild->sibling->sibling->sibling->sibling;
               temp=temp->sibling->sibling;//moving into colon ke baad wala node
           }
           //
           exp_table_record.record.primitive_type=temp->firstChild->Node.terminal.t; //INT/BOOl/REAL(terminal)
           //daalnaa
           //storing to <single_primitive> and <primitive>
           temp->parent->exp_type=exp_table_record;
           temp->parent->parent->exp_type=exp_table_record;
         }
else if (temp->isTerm == 0 && temp->Node.nonTerminal.nt == array)
        {
            exp_table_record.tag = array;
            exp_table_record.info = Static;
            temp = temp->firstChild;
            
            int line = temp->firstChild->Node.terminal.line_num;
            if (temp->isTerm == 0 && temp->Node.nonTerminal.nt == single_array)
            {
                varlist_pointer = temp = temp->firstChild->sibling;
                temp = temp->sibling->sibling; //moving into colon ke baad wala node
              
            }
            else
            {
                varlist_pointer = temp = temp->firstChild->sibling->sibling->sibling->sibling;
                temp = temp->sibling->sibling; //moving into colon ke baad wala node
                
            }
            
            temp = temp->sibling; //(ignore just after colon, arrray written)
            
            //<array_dim> hai aab, in temp
            parseTree *store = temp; //at <array_dim>

            int count = 0;
            int strcount=0;
             int strcount2=0;
            int r1 = -1, r2 = -1;
            int **tem = (int **)malloc(2 * sizeof(int *));
            int s_g=1;
            int s_g2=1;
           char **l_indexes = (char **)malloc(sizeof(char *));
            char **u_indexes = (char **)malloc(sizeof(char *));

            // int strCount=0;
            // char **indexes;
            int g = 1, b = 2;
            //char ** indexes = (char **)malloc(sizeof(char *));
            
            do
            {
                
                temp = temp->firstChild; //(moving into the child of  <array_dim>)
                temp = temp->sibling;
                
                
                //id or num =temp->firstChild;

                if (temp->firstChild->Node.terminal.t == ID) //checking if dimension is ID.
                {
                    exp_table_record.info = Dynamic;
                    r1 = -1;
                }
                else{ // If dimension is NUM
                    r1 = atoi(temp->firstChild->Node.terminal.lexeme);
                    if(r1==-1)r1=-100;
                }

                //
            if(r1==-1){
                    if (strcount >= s_g )
                    {
                        l_indexes = (char **)realloc(l_indexes,  (s_g*2) * sizeof(char *));
                        s_g=s_g*2;
                    }
                   // printf("here\n");
                    int len=strlen(temp->firstChild->Node.terminal.lexeme);
                    l_indexes[strcount] = (char *)malloc(len*sizeof(char)); //allocating space to store left and right index
                    strcpy(l_indexes[strcount] ,temp->firstChild->Node.terminal.lexeme);
                     // Storing ID in form of string
                    //printf("l-> %s  :  %s %d\n",temp->firstChild->Node.terminal.lexeme,l_indexes[strcount],strcount );
                  strcount++;
                    
                }
                else{
                    if (strcount >= s_g )
                    {
                        l_indexes = (char **)realloc(l_indexes,  (s_g*2) * sizeof(char *));
                        s_g=s_g*2;
                    }
                    int len=12;
                    l_indexes[strcount ] = (char *)malloc(len*sizeof(char)); //allocating space to store left and right index
                    strcpy(l_indexes[strcount ] ,"NumericValue");
                     // Storing ID in form of string
                    // printf("l-> %s %s %d\n",temp->firstChild->Node.terminal.lexeme,l_indexes[strcount],strcount );
                      strcount++;
                }

                temp = temp->sibling->sibling; //ignoring .. (DD)

                if (temp->firstChild->Node.terminal.t == ID) // checking if dimension is ID
                {
                    exp_table_record.info = Dynamic;
                  
                    r2 = -1;
                }
                else{ // If dimension is NUM
                    r2 = atoi(temp->firstChild->Node.terminal.lexeme);
                    if(r2==-1)r2=-100;
                }
                if(r2==-1){
                   // printf("here2\n");
                    if (strcount2 >= s_g2 )
                    {
                        u_indexes = (char **)realloc(u_indexes,  (s_g2*2) * sizeof(char *));
                        s_g2=s_g2*2;
                    }
                    int len=strlen(temp->firstChild->Node.terminal.lexeme);
                    u_indexes[strcount2 ] = (char *)malloc(len*sizeof(char)); //allocating space to store left and right index
                    strcpy(u_indexes[strcount2 ] ,temp->firstChild->Node.terminal.lexeme);
                     // Storing ID in form of string
                   // printf("u-> %s : %s %d\n",temp->firstChild->Node.terminal.lexeme,u_indexes[strcount2],strcount2 );
                    strcount2++;
                    
                }
                else{
                   // printf("here2\n");
                    if (strcount2 >= s_g2 )
                    {
                       // printf("here2\n");
                        u_indexes = (char **)realloc(u_indexes,  (s_g2*2) * sizeof(char *));
                        s_g2=s_g2*2;
                    }
                    int len=12;
                    u_indexes[strcount2] = (char *)malloc(len*sizeof(char)); //allocating space to store left and right index
                    strcpy(u_indexes[strcount2] ,"NumericValue");
                    //printf("u -> %s %s %d\n",temp->firstChild->Node.terminal.lexeme,u_indexes[strcount2],strcount2 );
                     //Storing ID in form of string
                    strcount2++;
                }
                
                   temp = temp->sibling->sibling; //reaches <array_dim>
                
             
                //chk type(dynamic), dimension(lower<upper), read, and error report, maintain counter for Dimension Count, dimension=count;
                //store to type_Expression_record.record.arr_record;
                if ((r1 == -1 && r2 >= 0) || (r1 >= 0 && r2 == -1) || (r1 >= 0 && r2 >= 0 && r1 <= r2) || (r1 == -1 && r2 == -1)) //(-1 for ID)
                //checking if lower_index < higher_index and ignore if one (or both) index are ID and NUM should be >= 0
                {
                    count++;
                    exp_table_record.record.arr_record.dim = count;
                    if (count > g * b)
                    {
                        tem = (int **)realloc(tem, 2 * (count - 1) * sizeof(int *));
                        g++;
                    }
                    tem[count - 1] = (int *)malloc(2 * sizeof(int)); //allocating space to store left and right index
                    tem[count - 1][0] = r1;
                    tem[count - 1][1] = r2;
                    exp_table_record.record.arr_record.dim_bound = tem;
                    exp_table_record.record.arr_record.l_indexes=l_indexes;
                    exp_table_record.record.arr_record.u_indexes=u_indexes;
                    
                    store->parent->exp_type = exp_table_record;
                    store->parent->parent->exp_type = exp_table_record;
                }
                else //if lower_range becomes greater than higher_range
                {
                    exp_table_record.tag=not_app;
                    exp_table_record.info = N_A;        //erroneous type declaration, storing N_A in the field in node.
                    
                    
                    int dep = 0 ;
                    printf("%d   DECLARATION   ***   ***   ***   ***   ***   %d   Array_Range_Mismatch \n", line, dep);
                    break;
                }

            } while (temp != NULL);
            //storing to single_array and array
            
            //temp2=daalde
        }
        //while exiting put in node

    //    else if(temp->isTerm==0&&temp->Node.nonTerminal.nt==jagged_array){
    //        temp=temp->firstChild;
    //        if(temp->isTerm==0&&temp->Node.nonTerminal.nt==jagged_2d_array){
    //        exp_table_record.tag=jagged_array;
    //        exp_table_record.info=N_A;
    //        temp=temp->firstChild; 
    //             if(temp->isTerm==0&&temp->Node.nonTerminal.nt==single_jagged2darray){
    //                 varlist_pointer=temp=temp->firstChild->sibling;
    //                 temp=temp->sibling->sibling;//moving into colon ke baad wala node
    //             }
    //             else{
    //                 varlist_pointer=temp=temp->firstChild->sibling->sibling->sibling->sibling;
    //                 temp=temp->sibling->sibling;//moving into colon ke baad wala node
    //             }
    //        temp=temp->sibling->sibling;//(ignore just after colon, jagged and arrray written)
    //         //<jagged_2d_dim> hai , in temp
    //         parseTree * store=temp;//at <jagged_2d/3d_dim>
    //         int l_bound=temp->firstChild->sibling->firstChild;
    //         int u_bound=temp->firstChild->sibling->sibling->sibling->firstChild;
    //         int dimension=2;
    //         //temp <jagged_dim> pe hi hai
    //         if(l_bound<=u_bound){//chk =
    //             //traverse for jaglines
    //             temp=temp->sibling->sibling->sibling->sibling; //reach <jag_lines>
    //             //read all jag_lines one by one upto, NULL
    //             do{
    //             //temp pointing on <jag_line>
    //             temp=temp->firstChild;
    //             parseTree* temp_jag=temp->firstChild;  //point to R1             
    //             temp_jag=temp_jag->sibling->sibling;//pointing on NUM
    //             int indx=temp_jag;
    //             //chk index in l_bound,u_bound and particularly increasing//#######TO BE DONE
    //             temp_jag=temp_jag->sibling->sibling->sibling->sibling;//pointing to size NUM(size NUM)
    //             int sz=temp_jag;
    //             //store in the cnt of jagged_R2_type
    //             temp_jag=temp_jag->sibling->sibling->sibling->sibling;//pointing to jag_list;
    //             //read all <jag_list(initialisation wala values)>
    //             //validity CHK ACCORDING TO SZ variable me size kya ha
    //             //epsion empty ; ; checking required


    //             //moving temp to <jag_lines>
    //             temp=temp->sibling;
    //             }while(temp!=NULL);

    //         }
    //         else{
    //             //error
    //         }
    //         store->parent->exp_type=exp_table_record;
    //         store->parent->parent->exp_type=exp_table_record;
    //         store->parent->parent->parent->exp_type=exp_table_record;
            
    //       // exp_table_record.record.j_arr_record=temp->child->value;

    //    }
    //    else if(temp->isTerm==0&&temp->Node.nonTerminal.nt==jagged_3d_array){
    //        exp_table_record.tag=jagged_array;
    //        exp_table_record.info=N_A;
    //        temp=temp->firstChild; 
    //        if(temp->isTerm==0&&temp->Node.nonTerminal.nt==single_jagged3darray){
    //            varlist_pointer=temp=temp->firstChild->sibling;
    //            temp=temp->sibling->sibling;//moving into colon ke baad wala node
    //        }
    //        else{
    //            varlist_pointer=temp=temp->firstChild->sibling->sibling->sibling->sibling;
    //            temp=temp->sibling->sibling;//moving into colon ke baad wala node
    //        }
    //        temp=temp->sibling->sibling;//(ignore just after colon, jagged and arrray written)
    //         //<jagged_dim> hai , in temp
    //          parseTree * store=temp;//at <jagged_2d/3d_dim>
    //     //CONTINUE THIS WORK//CONTINUE THIS WORK//CONTINUE THIS WORK
    //         int l_bound=temp->firstChild->sibling->firstChild;
    //         int u_bound=temp->firstChild->sibling->sibling->sibling->firstChild;
    //         int dimension=3;
    //         if(l_bound<=u_bound){//chk =
    //             //kamm alag hoga.
    //         }
    //         else{
    //             //error
    //         }
    //         store->parent->exp_type=exp_table_record;
    //         store->parent->parent->exp_type=exp_table_record;
    //         store->parent->parent->parent->exp_type=exp_table_record;
    //     //   exp_table_record.record.j_arr_record=temp->firstChild;
    //    }
    //    }
       //reach, type expression record ready,
       //populate varlist_pointer, with typeexpression,
       //populate typeExpressionTable with variable created.
       if(varlist_pointer!=NULL){
       if(varlist_pointer->isTerm==1&&varlist_pointer->Node.terminal.t==ID){
          // printf("yaha\n");
            varlist_pointer->exp_type=exp_table_record;
         //   printf("%d\n\n\n",varlist_pointer->exp_type.tag);
            //append to typeExpression Table
          
            append_to_table(exp_table_record,varlist_pointer->Node.terminal.lexeme);
       }
       else{
           //traverse all IDs
           //printf("yaha\n");
           do{
           //    printf("yahan\n");
               varlist_pointer->exp_type=exp_table_record;
               varlist_pointer=varlist_pointer->firstChild;
                
               varlist_pointer->exp_type=exp_table_record;
               
//append to typeExpression Table
               append_to_table(exp_table_record,varlist_pointer->Node.terminal.lexeme);
               
               varlist_pointer=varlist_pointer->sibling;
              
           }while(varlist_pointer!=NULL);
       }
       }
       return;
   }

   
   
   
   /*********///RAJAT/************/
   
   
    else if(t->isTerm==0&&t->Node.nonTerminal.nt==assignment){
>>>>>>> b5201d7a1fdbe88476c185ec4c82aa191e8e0159
        traverse_parse_tree(t->firstChild);
        if (t->firstChild->sibling != NULL)
        {
            traverse_parse_tree(t->firstChild->sibling);
        }
        return;
    }

    else if (t->isTerm == 0 && t->Node.nonTerminal.nt == assignment_stmt)
    { //<assignment_stmt>
        // //=> <arr_pid> EQUALS <expression> SEMICOLON
        // type_left;type_right;
        // //CONTINUE THIS WORK//CONTINUE THIS WORK//CONTINUE THIS WORK
        // t=t->firstChild;(check validity)//-->boundck, etc if array type var                   int a = 2 + 3.7 + 5;
        // t=t->sibling->sibling;//move to expree(send to function, find return type) -- , + , &&
        // if(type_left!=type_right){
        //    // ERROR //otherwise no isseus
        // }
        return;
    }
}
void printTypeExpressionsTable(TypeExpressionTable T[], char *filename)
{
    FILE *fp = fopen(filename, "w");
    if (fp == NULL)
    {
        printf("Error opening");
        return;
    }

    fprintf(fp, "%10.10s %15.15s %15.15s  %15.15s \n", "Variable", "Type", "Bind_type", "Type_Expression");
    for (int i = 0; i < m; i++)
    {
        char var_name[200], dec_name[200], bind_name[200];
        strcpy(var_name, T[i].var_name); //field1
        bind_info info = T[i].info;
        strcpy(bind_name, string_bind[T[i].info]); //field2
        NonTerminal tag = T[i].tag;
        strcpy(dec_name, NonTerminalMap[T[i].tag]); //field3

        fprintf(fp, "%10.10s %15.15s %15.15s ", var_name, dec_name, bind_name);

        //field4 here on
        if (tag == primitive)
        { //Primitive
            fprintf(fp, " <basicType=%s>", TerminalMap[T[i].record.primitive_type]);

            //print name, dec_type, bind_info, typeExpression
        }
        else if (tag == array)
        {
            //Array
            int dim = T[i].record.arr_record.dim;
            fprintf(fp, " <type=rectangularArray, dimensions=%d, ", dim);

            for (int j = 0; j < dim; j++)
            {
                int a = T[i].record.arr_record.dim_bound[j][0];
                int b = T[i].record.arr_record.dim_bound[j][1];
                //case for var_name in d_bind
<<<<<<< HEAD
                if (a != -1 && b != -1)
                    fprintf(fp, "range_R%d= (%d, %d), ", j + 1, a, b);
                else if (a == -1 && b != -1)
                    fprintf(fp, "range_R%d= (%s, %d), ", j + 1, T[i].record.arr_record.l_indexes[j], b);
                else if (a != -1 && b == -1)
                    fprintf(fp, "range_R%d= (%d, %s), ", j + 1, a, T[i].record.arr_record.u_indexes[j]);
                else if (a == -1 && b == -1)
                    fprintf(fp, "range_R%d= (%s, %s), ", j + 1, T[i].record.arr_record.l_indexes[j], T[i].record.arr_record.u_indexes[j]);
=======
                      if(a!=-1&&b!=-1)fprintf(fp,"range_R%d= (%d, %d), ",j+1,a,b);
                            else if(a==-1&&b!=-1)fprintf(fp,"range_R%d= (%s, %d), ",j+1,T[i].record.arr_record.l_indexes[j],b);
                            else if(a!=-1&&b==-1)fprintf(fp,"range_R%d= (%d, %s), ",j+1,a,T[i].record.arr_record.u_indexes[j]);
                            else if(a==-1&&b==-1)fprintf(fp,"range_R%d= (%s, %s), ",j+1,T[i].record.arr_record.l_indexes[j],T[i].record.arr_record.u_indexes[j]);
                 
>>>>>>> b5201d7a1fdbe88476c185ec4c82aa191e8e0159
            }
            fprintf(fp, "basicElementType = Integer>");
            //basic=Integer by def
        }
        else if (tag == jagged_array)
        { //Jagged_ARRAY
            int dim = T[i].record.j_arr_record.dim;

            fprintf(fp, " <type =jaggedArray, dimensions=%d, ", dim);

            if (dim == 2)
            {
                int high = T[i].record.j_arr_record.r1_high;
                int low = T[i].record.j_arr_record.r1_low;
                fprintf(fp, "range_R1=(%d, %d) range_R2 = (", low, high);

                for (int j = 0; j < high - low + 1; j++)
                {
                    fprintf(fp, " %d ", T[i].record.j_arr_record.dim_bound._line[j]);
                    if (j != high - low)
                        fprintf(fp, ",");
                    //from (low,high) gives size  , 0 index
                }
            }
            else
            { //dim==3
                int high = T[i].record.j_arr_record.r1_high;
                int low = T[i].record.j_arr_record.r1_low;
                fprintf(fp, "range_R1=(%d, %d) range_R2 = ( ", low, high);
                //  <type =jaggedArray, dimensions=3, range_R1=(4, 7),
                //3 [ 5, 3, 5] ,
                //1 [  5], 2 [ 4, 3] ,3 [ 5, 4, 4]
                for (int j = 0; j < high - low + 1; j++)
                {
                    int m = T[i].record.j_arr_record.dim_bound.jag_line[j][0];
                    fprintf(fp, "%d [", m);
                    for (int k = 0; k < m; k++)
                    {
                        fprintf(fp, " %d", T[i].record.j_arr_record.dim_bound.jag_line[j][k + 1]);
                        if (k != m - 1)
                            fprintf(fp, ",");
                    }
                    fprintf(fp, " ]");
                    if (j != high - low)
                        fprintf(fp, ", ");
                }
            }
            fprintf(fp, "), basicElementType = integer>");

            //basic=Integer by def
        }
        else
        {
            fprintf(fp, " NOT A VALID TYPE EXPRESSION");
        }
        fprintf(fp, "\n");
    }
    fclose(fp);
}
/******************FUNCTION END*************************************/

int main()
{
    { // KEYWORD TABLE
        ha[0][0] = "program";
        ha[0][1] = "PROGRAM";
        ha[1][0] = "declare";
        ha[1][1] = "DECLARE";
        ha[2][0] = "list";
        ha[2][1] = "LIST";
        ha[3][0] = "of";
        ha[3][1] = "OF";
        ha[4][0] = "variables";
        ha[4][1] = "VARIABLES";
        ha[5][0] = "size";
        ha[5][1] = "SIZE";
        ha[6][0] = "values";
        ha[6][1] = "VALUES";
        ha[7][0] = "integer";
        ha[7][1] = "INTEGER";
        ha[8][0] = "real";
        ha[8][1] = "REAL";
        ha[9][0] = "boolean";
        ha[9][1] = "BOOLEAN";
        ha[10][0] = "array";
        ha[10][1] = "ARRAY";
        ha[11][0] = "jagged";
        ha[11][1] = "JAGGED";
        ha[12][0] = "R1";
        ha[12][1] = "R1";
        op[0][0] = "+";
        op[0][1] = "PLUS";
        op[1][0] = "-";
        op[1][1] = "MINUS";
        op[2][0] = "*";
        op[2][1] = "MUL";
        op[3][0] = "/";
        op[3][1] = "DIVIDE";
        op[4][0] = "(";
        op[4][1] = "BROP";
        op[5][0] = ")";
        op[5][1] = "BRCL";
        op[6][0] = "{";
        op[6][1] = "CURLYOP";
        op[7][0] = "}";
        op[7][1] = "CURLYCL";
        op[8][0] = "[";
        op[8][1] = "SQOP";
        op[9][0] = "]";
        op[9][1] = "SQCL";
        op[10][0] = "&&&";
        op[10][1] = "AND";
        op[11][0] = "|||";
        op[11][1] = "OR";
        op[12][0] = ":";
        op[12][1] = "COLON";
        op[13][0] = ";";
        op[13][1] = "SEMICOLON";
        op[14][0] = "..";
        op[14][1] = "DD";
        op[15][0] = "=";
        op[15][1] = "EQUALS";
    }
    // 1. Read the grammar.
    grammar *g = malloc(NON_TERMINALS * sizeof(grammar));
    readGrammar("gr.txt", g);

    // 2. Tokenize the source code
    tokeniseSourcecode("file2.txt", head);

    // 3. Create the parseTree
    //create the start node
    posToken = head;
    parseTree *p = malloc(sizeof(parseTree));
    p->isTerm = 0;
    p->Node.nonTerminal.expRule = NULL;
    p->Node.nonTerminal.nt = s;
    p->parent = p;
    p->sibling = NULL;
    p->firstChild = NULL;

    createParseTree(p, g);

    if (posToken != NULL)
        printf("ERRRRRRORRRRRRRRRRR\n");
    //4. Printing the parse tree
    printParseTree(p);

    traverse_parse_tree(p);
    printParseTree(p);
    printTypeExpressionsTable(table, "new2.txt");
    return 0;
}