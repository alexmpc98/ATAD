typedef struct {
     int week;
     int rank;
     char* nickname;
     int total_score;
     int correct_answers;
     int incorrect_answers;
} KahootReport;


KahootReport KahootReportCreate(int week, int rank, char* nickname, int total_score,int correct_answers, int incorrect_answers);
void KahootReportPrint(KahootReport kr);