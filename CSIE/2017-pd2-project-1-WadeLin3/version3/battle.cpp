/************************************************
* The strategy of battle.
* Choose the best card to sumon.
************************************************/
# include "minion.h"
# include "battle.h"
# include <string>
# include <iostream>
          
static int atk = 4;
static int tnk = 5;
static int sup = 3;

char choose_best_card(minion a,minion b,minion c,minion d){
	// find powerful minion
	char n = find_power(a,b,c,d);
	if (n != 0) return n;
	else {
		if (tnk >= atk && tnk >= sup){
			n = find_tank(a,b,c,d);
			if (n != 0) return n;
                        else if (atk >= sup){
				n = find_attack(a,b,c,d);
                                if (n != 0) return n;
                                else return find_support(a,b,c,d);
                        }
		}
		if (atk >= tnk && atk >= sup){
	                n = find_attack(a,b,c,d);
	                if (n != '0') return n;
	                else if (sup >= tnk){
	                        n = find_support(a,b,c,d);
	                        if (n != '0') return n;
	                        else return find_tank(a,b,c,d);
	                }
	        }
		if (sup >= atk && sup >= tnk){
	                n = find_support(a,b,c,d);
	                if (n != '0') return n;
	                else if (atk >= tnk){
	                        n = find_attack(a,b,c,d);
	                        if (n != '0') return n;
	                        else return find_tank(a,b,c,d);
	                }
	        }
	}
}

char find_power(minion a,minion b,minion c,minion d){
	if      (a.getCL() == "power") return a.getNo();
	else if (b.getCL() == "power") return b.getNo();
	else if (c.getCL() == "power") return c.getNo();
	else if (d.getCL() == "power") return d.getNo();
	else return 0;
}
char find_tank(minion a,minion b,minion c,minion d){
	if      (a.getCL() == "tank") return a.getNo();
	else if (b.getCL() == "tank") return b.getNo();
        else if (c.getCL() == "tank") return c.getNo();
        else if (d.getCL() == "tank") return d.getNo();
	else return 0;
}
char find_attack(minion a,minion b,minion c,minion d){
	if      (a.getCL() == "sniper") return a.getNo();
        else if (b.getCL() == "sniper") return b.getNo();
        else if (c.getCL() == "sniper") return c.getNo();
        else if (d.getCL() == "sniper") return d.getNo();
        else {
		if 	(a.getCL() == "attack") return a.getNo();
	        else if (b.getCL() == "attack") return b.getNo();
	        else if (c.getCL() == "attack") return c.getNo();
	        else if (d.getCL() == "attack") return d.getNo();
		else return 0;
	}
}
char find_support(minion a,minion b,minion c,minion d){
        if      (a.getCL() == "support") return a.getNo();
        else if (b.getCL() == "support") return b.getNo();
        else if (c.getCL() == "support") return c.getNo();
        else if (d.getCL() == "support") return d.getNo();
	else return 0;
}
int position_x(int status,char x){
	minion X(x);
	// default position:tnk atk sup pow sniper
	int dp[5]=         { 5 , 5 , 3 , 10, 2 }; 
		
	if (X.getCL() == "tank")     return dp[0];
	if (X.getCL() == "attack")   return dp[1];
	if (X.getCL() == "support")  return dp[2];
	if (X.getCL() == "power")    return dp[3];
	if (X.getCL() == "sniper")   return dp[4];
}
int position_y(int status,char x){
	minion X(x);
        // default position:tnk atk sup pow sniper
        int dp[5]=         { 23, 20, 17, 1 , 20};

        if (X.getCL() == "tank")     return dp[0];
        if (X.getCL() == "attack")   return dp[1];
        if (X.getCL() == "support")  return dp[2];
        if (X.getCL() == "power")    return dp[3];
	if (X.getCL() == "sniper")   return dp[4];
}
