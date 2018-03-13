#pragma once

class passport
{
private:
	int number_;
	int series_;
	string registration_place_{};
	time_t registration_date_{};
public:
	passport(int number, int series, const string place, time_t date);

	int get_number() const;
	int get_series() const;
	string get_place() const;
	time_t get_date() const;
	string get_full_info() const;
};
