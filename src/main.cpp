#include "Prison/Parser/Scanner.h"
#include "Prison/Parser/Lexer.h"
#include "Prison/Parser/Grammar.h"


#include "Prison/Util/Generic/HashMap.h"
#include "Prison/Util/Generic/LinkedList.h"

#include "Prison/AST/Scope.h"
#include "Prison/AST/Node.h"
#include "Prison/AST/Identifier.h"

#include "Prison/AST/Statements/Sequence.h"
#include "Prison/AST/Statements/If.h"

#include "Prison/AST/Operations/Binary/Assign.h"
#include "Prison/AST/Operations/Binary/Add.h"
#include "Prison/AST/Operations/Binary/LessThan.h"
#include "Prison/AST/Types/Int.h"
#include "Prison/AST/Types/Bool.h"


#include <iostream>
#include <typeinfo>
#include <regex>

using namespace Prison::Parser;
using namespace Prison::AST;
using namespace Prison::AST::Operations::Binary;
using namespace Prison::AST::Types;
using namespace Prison::AST::Statements;

// void testPointers() {
	// int four = 4;
	// int * p;
	// int * k;

	// p = &four;
	// k = &(*p);


	// std::cout << *p << " " << p << " " << &p << " " << &(*p) << '\n';
	// std::cout << *k << " " << k << " " << &k << " " << &(*k);
// }

// void testLexer() {
// 	std::cout << "Prison running\n";

// 	const char *tokenFile = "tokens.pri";

// 	const char *filename = "test.syntax";

// 	Scanner * scanner = new Scanner(filename);
// 	Lexer * lexer = new Lexer(scanner);
// 	Token token;

// 	while (!lexer->eof())
// 	{
// 		token = lexer->shift();
// 		std::cout << token.name << ' ' << token.value << ' ' << token.line << ':' << token.column << '\n';
// 	}

// 	delete lexer;

// 	int x = 15;
// }

void testLinkedList() {
	Prison::Util::Generic::LinkedList<long> * ll = new Prison::Util::Generic::LinkedList<long>();

	ll->link("twelwe", 12);

	ll->link("kutya", 13);
	// ll->link("kutya", 12);
	ll->link("cica", 14);
	// ll->link("cica", 12);

	ll->get("kutya");

	ll->unlink("kutya");

	ll->link("kutyus", 20);
	ll->link("mégegy", 20);

	ll->unlink("mégegy");
	ll->get("kutya");

	ll->unlink("twelwe");
	ll->unlink("cica");
	ll->unlink("kutyus");

	// for (long i = 0; i < 100000000; i++) {
	// 	ll->link("test", i);
	// 	ll->unlink("test");

	// 	std::cout << "iter " << i << "\n";
	// }

	delete ll;

	std::cout << "deleted";
}

void testHashMap() {
	Prison::Util::Generic::HashMap<int> * hashmap = new Prison::Util::Generic::HashMap<int>();

	hashmap->put("kutya", 13);
	hashmap->put("cica", 23);
}

void testAST() {
	Prison::Util::Generic::HashMap<Prison::AST::Node *> * map = new Prison::Util::Generic::HashMap<Prison::AST::Node *>();
	Prison::AST::Scope * scope = new Prison::AST::Scope(map);

	Identifier * id_x = new Identifier("x");
	Identifier * id_y = new Identifier("y");

	Identifier * id_z = new Identifier("z");

	Identifier * id_bool = new Identifier("bool");

	Int * int_1 = new Int(1);
	Int * int_2 = new Int(2);

	Add * add_1_2 = new Add(int_1, int_2);
	LessThan * less_than = new LessThan(id_y, id_x);


	Assign * assign_x = new Assign(id_x, add_1_2);
	Assign * assign_y = new Assign(id_y, int_2);
	Assign * assign_bool = new Assign(id_bool, less_than);

	Assign * assign_if = new Assign(id_z, int_1);
	Assign * assign_else = new Assign(id_z, int_2);

	Sequence * sequence = new Sequence();

	Sequence * sequenceIf = new Sequence();
	Sequence * sequenceElse = new Sequence();

	sequence->append(assign_x);
	sequence->append(assign_y);
	sequence->append(assign_bool);

	sequenceIf->append(assign_if);
	sequenceElse->append(assign_else);

	sequence->evaluate(scope);

	If * _if = new If(new Bool(false), sequenceIf, sequenceElse);

	_if->evaluate(scope);

	std::cout << "OK\n";
}

bool callback(const char * key, const char * regex) {
	std::cout << key << regex << "\n";

	return true;
}

void testGrammar() {
	Grammar * grammar = new Grammar;

	// grammar->each(&callback);

	const char * token = "token";

	auto cb = [token](const char * key, const char * regex) -> bool {
		std::cout << key << regex << token << "\n";

		return true;
	};

	grammar->each(cb);
}

int main() {

	// testPointers();
	// testLexer();
	// testLinkedList();
	// testHashMap();
	// testAST();
	testGrammar();

	std::cout << "OK";
	return 0;
}
