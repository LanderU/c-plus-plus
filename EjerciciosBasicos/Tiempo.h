class Time
{
public:
	void Set( int, int, int );
	void Increment();
	void Write() const;
	bool Equal( Time ) const;
	bool LessThan( Time ) const;
	Time( int, int, int ); // Constructor
	Time(); //Constructor
private:
	int hrs;
	int mins;
	int secs;
};
