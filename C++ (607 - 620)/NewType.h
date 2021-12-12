#pragma once
//Ngày tháng năm
struct Date {
	int day;
	int month;
	int year;
}; typedef struct Date date;
//Thời gian
struct Time {
	int hour;
	int minute;
	int second;
}; typedef struct Time timee;
//607: Một tỉnh
struct Province {
	int codex;
	char name[31];
	double surface;
};
typedef struct Province province;

//608: Hộp sữa
struct Milkbox {
	char brand[21];
	double weight;
	date expiry;
};
typedef struct Milkbox milk;

//609: Vé xem phim
struct Ticket {
	char name[21];
	long price;
	timee dis;
	date day;
};
typedef struct Ticket tic;

//610: Mặt hàng
struct Product {
	char name[21];
	long price;
	long quantity;
}; typedef struct Product pro;

//611: Chuyến bay
struct Flight {
	char code[6];
	date day;
	timee time;
	char from[21];
	char dest[21];
}; typedef struct Flight fly;

//612: Cầu thủ
struct SoccerPlayer {
	char code[11];
	char name[31];
	date born;
}; typedef struct SoccerPlayer socplay;

//613: Đội bóng
struct FootballClub {
	char code[6];
	char name[31];
	socplay list[30];
}; typedef struct FootballClub fc;

//614: Nhân viên
struct Staff {
	char code[6];
	char name[31];
	double sala;
}; typedef struct Staff staff;

//615: Thí sinh
struct UniStudent {
	char code[6];
	char name[31];
	double math;
	double phys;
	double chem;
	double total;
}; typedef struct UniStudent candi;

//616: Luận văn
struct Essay {
	char code[11];
	char name[101];
	char stu[31];
	char teac[31];
	int year;
}; typedef struct Essay ess;

//617: Học sinh
struct Student {
	char name[31];
	double math;
	double lit;
	double avg;
}; typedef struct Student stu;

//618 - 613 là tương tự nhau, 619, 620 tương tự mấy bài trên
