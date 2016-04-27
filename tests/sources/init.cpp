#include <Matrix.hpp>
#include <catch.hpp>
#include <fstream>

SCENARIO("Matrix init", "[init]") {

	GIVEN("The number of rows and columns") {

		auto rows = 3;
		auto columns = 3;

		WHEN("Create instansce of Matrix") {

			Matrix<int> matrix(rows, columns);

			THEN("The number of rows and columns must be preserved") {

				REQUIRE(matrix.STR() == rows);
				REQUIRE(matrix.STOLB() == columns);
			}
		}
	}
}


SCENARIO("Matrix +", "[addition]") {
	Matrix<int> A = Matrix<int>(2, 2);
	std::ifstream("A2x2.txt") >> A;
	Matrix<int> B = Matrix<int>(2, 2);
	std::ifstream("B2x2.txt") >> B;
	Matrix<int> expected = Matrix<int>(2, 2);
	std::ifstream("A+B2x2.txt") >> expected;

	Matrix<int> result = A + B;
	REQUIRE(result == expected);
}

SCENARIO("Matrix *", "[multiplication]") {
	Matrix<int> A = Matrix<int>(2, 2);
	std::ifstream("A2x2.txt") >> A;
	Matrix<int> B = Matrix<int>(2, 2);
	std::ifstream("B2x2.txt") >> B;
	Matrix<int> expected = Matrix<int>(2, 2);
	std::ifstream("A*B2x2.txt") >> expected;
        Matrix<int> result  = A * B;
	REQUIRE(result == expected);
}

SCENARIO ("Matrix []", "[getrow]") {
	Matrix<int> A (2,2);
	std::ifstream("A2x2.txt") >> A;
	int *stroka2;
	stroka2=A[1];
	for(int i=0; i<2; i++){
	REQUIRE(stroka2[i]==1);
	}
}

SCENARIO ("Dimension sum", "[d-error]") {
	int x=0;
	Matrix<int> A (2,2);
	Matrix<int> B(2,3);
	try {
		A + B;
	}
	catch(Dimension &err)
	{
	x=1;
	}
REQUIRE(x==1);
}

SCENARIO ("Dimension MULT", "[d-error]") {
	int x=0;
	Matrix<int> A (2,2);
	Matrix<int> B(2,3);
	try {
		A * B;
	}
	catch(Dimension &err)
	{
	x=1;
	}
REQUIRE(x==1);
}

SCENARIO("File isn't opened", "[f-error]") {
	int x=0;
	Matrix<int> A (2,2);
	try {
	std::ifstream("A2x3.txt") >> A;
	}
	catch(FileNotOpen &err)
	{
		x=1;
	}
	REQUIRE(x==1);
}

SCENARIO("Wrong Index", "[i-error]"){
	int x=0;
	Matrix<int> A(2,2);
	try {
		A[-1];
	}
	catch(WrongIndex &err){
		x=1;
	}
	REQUIRE(x==1);
}

