#include<iostream>
#include<string>
using namespace std;

enum enQuestionLevel { EasyLevel = 1, MedLevel = 2, HardLevel = 3, Mix = 4 };

enum enOpreationType { Add = 1, Sub = 2, Mul = 3, Div = 4, MixOp = 5 };

struct stQuestion {
	int Number1;
	int Number2;
	enOpreationType OpreationType;
	enQuestionLevel QuestLevel;
	int CorrectAnswer = 0;
	int PlayerAnswer = 0;
	bool AnswerResult = false;
};
struct stQuizz {
	stQuestion QuestionList[100];
	short NumberOfQuestion;
	enQuestionLevel QuestionLevel;
	enOpreationType OpType;
	int NumberOfRightAnswer = 0;
	int NumberOfWrongAnswer = 0;
	bool IsPass = false;
};

void ResetScreen() {
	system("cls");
	system("color 0F");
}

short ReadHowManyQuastion() {
	short NumberQuastion;
	do
	{
		cout << "How Manay Quistion Do You want To answer ? ";
		cin >> NumberQuastion;
	} while (NumberQuastion < 1 || NumberQuastion > 10);
	return NumberQuastion;
}

enQuestionLevel ReadQuestionLevel() {
	short QuestionLevel = 0;
	do
	{
		cout << "Enter Quistion Level [1] Eazy, [2] Med, [3] Hard, [4] Mix ? ";
		cin >> QuestionLevel;
	} while (QuestionLevel < 1 || QuestionLevel > 4);
	return (enQuestionLevel)QuestionLevel;
}

enOpreationType ReadOpType() {
	short OpreationType;
	do
	{
		cout << "Enter Operation Type [1] Add, [2] Sub , [3] Mul, [4] Div, [5] Mix ? ";
		cin >> OpreationType;
	} while (OpreationType < 1 || OpreationType > 5);
	return (enOpreationType)OpreationType;
}

int RandomNumber(int From, int To) {
	return rand() % (To - From + 1) + From;
}

enOpreationType GetRandomOpType() {
	int Op = RandomNumber(1, 4);
	return (enOpreationType)Op;
}

int SimpleClaculator(int Number1, int Number2, enOpreationType Optype) {
	switch (Optype) {
	case enOpreationType::Add:
		return Number1 + Number2;
	case enOpreationType::Sub:
		return Number1 - Number2;
	case enOpreationType::Mul:
		return Number1 * Number2;
	case enOpreationType::Div:
		return Number1 / Number2;
	default:
		return Number1 + Number2;
	}
}

int ReadQuestionAnswer() {
	int answer = 0;
	cin >> answer;
	return answer;
}

stQuestion GenerateQuestion(enQuestionLevel QuestionLevel, enOpreationType OpType) {
	stQuestion Question;
	if (QuestionLevel == enQuestionLevel::Mix) {
		QuestionLevel = (enQuestionLevel)RandomNumber(1, 3);
	}
	if (OpType == enOpreationType::MixOp) {
		OpType = GetRandomOpType();
	}
	Question.OpreationType = OpType;

	switch (QuestionLevel) {
	case enQuestionLevel::EasyLevel:
		Question.Number1 = RandomNumber(1, 10);
		Question.Number2 = RandomNumber(1, 10);

		Question.CorrectAnswer = SimpleClaculator(Question.Number1, Question.Number2, Question.OpreationType);
		Question.QuestLevel = QuestionLevel;
		return Question;
	case enQuestionLevel::MedLevel:
		Question.Number1 = RandomNumber(10, 50);
		Question.Number2 = RandomNumber(10, 50);

		Question.CorrectAnswer = SimpleClaculator(Question.Number1, Question.Number2, Question.OpreationType);
		Question.QuestLevel = QuestionLevel;
		return Question;
	case enQuestionLevel::HardLevel:
		Question.Number1 = RandomNumber(50, 100);
		Question.Number2 = RandomNumber(50, 100);

		Question.CorrectAnswer = SimpleClaculator(Question.Number1, Question.Number2, Question.OpreationType);
		Question.QuestLevel = QuestionLevel;
		return Question;

	}
	return Question;
}

void GenerateQuizzQuestions(stQuizz& Quizz) {
	for (int Question = 0; Question < Quizz.NumberOfQuestion; Question++) {
		Quizz.QuestionList[Question] = GenerateQuestion(Quizz.QuestionLevel, Quizz.OpType);


	}
}

string GetOpTypeSymbol(enOpreationType OpType) {
	string arrOpreationType[5] = { "+" , "- ", "*" , "/" , "Mix" };
	return arrOpreationType[OpType - 1];
}

void PrintQuistion(stQuizz& Quizz, short QuestionNumber) {

	cout << "\n";
	cout << "Question [" << QuestionNumber + 1 << "/" << Quizz.NumberOfQuestion << "] \n\n";
	cout << Quizz.QuestionList[QuestionNumber].Number1 << endl;
	cout << Quizz.QuestionList[QuestionNumber].Number2 << " ";
	cout << GetOpTypeSymbol(Quizz.QuestionList[QuestionNumber].OpreationType) << endl;
	cout << "\n---------------" << endl;
}

void SetScreenColor(bool answer) {
	if (!answer)
	{
		system("color 4F");
		cout << "\a";
	}
	else
		system("color 2F");

}

void CorrectTheQuestionAnswer(stQuizz& Quizz, short QuestionNumber) {
	if (Quizz.QuestionList[QuestionNumber].PlayerAnswer != Quizz.QuestionList[QuestionNumber].CorrectAnswer) {
		Quizz.QuestionList[QuestionNumber].AnswerResult = false;
		Quizz.NumberOfWrongAnswer++;

		cout << "Wrong Answer :-( \n";
		cout << "The Right Answer is : ";
		cout << Quizz.QuestionList[QuestionNumber].CorrectAnswer;
		cout << "\n";
	}
	else
	{
		Quizz.QuestionList[QuestionNumber].AnswerResult = true;
		Quizz.NumberOfRightAnswer++;
		cout << "Correct Answer :-)";
		cout << "\n";
	}
	cout << endl;
	SetScreenColor(Quizz.QuestionList[QuestionNumber].AnswerResult);
}

void AskAndCorrectQuestionListAnswers(stQuizz& Quizz) {

	for (int QuestionNumber = 0; QuestionNumber < Quizz.NumberOfQuestion; QuestionNumber++) {

		PrintQuistion(Quizz, QuestionNumber);
		Quizz.QuestionList[QuestionNumber].PlayerAnswer = ReadQuestionAnswer();

		CorrectTheQuestionAnswer(Quizz, QuestionNumber);
	}
	Quizz.IsPass = (Quizz.NumberOfRightAnswer >= Quizz.NumberOfWrongAnswer);
}

string GetFinalResultText(bool Result) {
	if (Result)
		return "PASS :-)";
	else
		return "Fail :-(";
}

string GetOpreationTypeName(int OpType) {
	string arrOpreationType[5] = { "+" , "- ", "*" , "/" , "Mix" };
	return arrOpreationType[OpType - 1];
}

string GetQuistionLevelName(int Level) {
	string arrOpreationType[4] = { " Easy "," Med ", "Hard ", "Mix" };
	return arrOpreationType[Level - 1];
}

void PrintQuizResults(stQuizz QuizzResult) {

	cout << "\n--------------------------\n\n";
	cout << "Final Result Is " << GetFinalResultText(QuizzResult.IsPass);
	cout << "\n--------------------------\n";
	cout << "----------- [ Quiz Result ] -----------\n";

	cout << "Number Of Quistion     : " << QuizzResult.NumberOfQuestion << endl;
	cout << "Quistion Level         : " << GetQuistionLevelName(QuizzResult.QuestionLevel) << endl;
	cout << "OpType		       : " << GetOpreationTypeName(QuizzResult.OpType) << endl;
	cout << "Number Of Right Answer : " << QuizzResult.NumberOfRightAnswer << endl;
	cout << "Number Of Wrong Answer : " << QuizzResult.NumberOfWrongAnswer << endl;

	cout << "--------------------------------------\n";

	//SetWinnerScreenColor(FinalGameResult.GameWinner);
}

void PlayMathGame() {

	stQuizz Quizz;
	Quizz.NumberOfQuestion = ReadHowManyQuastion();
	Quizz.QuestionLevel = ReadQuestionLevel();
	Quizz.OpType = ReadOpType();

	GenerateQuizzQuestions(Quizz);

	AskAndCorrectQuestionListAnswers(Quizz);
	PrintQuizResults(Quizz);
}

void StartGame() {
	char PlayAgain = 'Y';
	do
	{
		ResetScreen();
		PlayMathGame();

		cout << "Do you want to play againe? Y/N : ";
		cin >> PlayAgain;
	} while (PlayAgain == 'Y' || PlayAgain == 'y');
}




int main()
{
	srand((unsigned)time(NULL));

	StartGame();

	return 0;
}


