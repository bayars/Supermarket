#include <sstream>
#include "../Sections/Games.hpp"

class AddofRecord{
public:
  void add(){
    string sql, GameName, BrandName;
    int ProductYear;
    double Price;
    Games Gameobj;
    std::cout << "Game Name: " << std::endl;
    std::cin >> GameName;
    std::cout << "Brand Name: " << std::endl;
    std::cin >> BrandName;
    std::cout << "Price: " << std::endl;
    std::cin >> Price;
    std::cout << "Product Year: " << std::endl;
    std::cin >> ProductYear;
    sql = "INSERT INTO games (PRODUCTNAME,BRANDNAME,PRICE,PRODUCTYEAR) VALUES ('" + GameName + "','" + BrandName  + "','" + InttoString(Price) + "','" + InttoString(ProductYear) +"');";
    PostgresConnection PostgresConn;
    if ( PostgresConn.Add(sql) == 0 ){
      std::cout << "The record added successfully!";
	}else{
      std::cout << "Something Gone Wrong!";
    }
  }
  string InttoString(int number){
    ostringstream temp;
    temp << number;
    return temp.str();
  }
};
