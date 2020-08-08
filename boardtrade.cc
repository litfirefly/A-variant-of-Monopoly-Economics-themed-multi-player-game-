else if (command[0]=="trade"){
	if (command.size()!=4){
		int index = 0;
		for (int i=0; i < players.size(); i++){
			if (players[currPlayer]->getName()==command[1]){
				int value=-1;
				if (stoi(command[3],value)){
					if (players[].getMoney()>=value){
						cout << "Does " << command[3] << " accept? (Type accept to accept, anything else to reject)" << endl;
						string accept="";
						getline(accept);
						if (accept=="accept"){
							bool found=false;
							for (int i=0; i<squaresOwned;i++){
								if (squaresOwned[i]->getName()==command[2]){
									transferSquare(players[],squaredOned[i];
									players[]->subtractMoney(value);
									found=true;
									break;
								}
							}
							if (!found){
								cout << "You don't have the propety" << endl;	
							}
						}
						else{
							cout << "Trade rejected" << endl;
						}
					}
					else{
						cout << command[3] << " doesn't have enough money." << endl;
					}
				}

				else {
					bool found=false;
					int myIndex=-1;
					for (int i=0; i<squaresOwned;i++){
						if (squaresOwned[i]->getName()==command[2]){
							myIndex=i;	
							found=true;
							break;
						}
					}
					if (!found){
						cout << "You don't have the propety" << endl;	
						break;
					}
					else{
						cout << "Does " << command[3] << " accept? (Type accept to accept, anything else to reject)" << endl;
						string accept="";
						getline(accept);
						if (accept=="accept"){
							bool found=false;
							for (int i=0; i<players[index]->squaresOwned;i++){
								if (players[index]->squaresOwned[i]->getName()==command[2]){
									transferSquare(this,otherPlayers[index]->squaredOned[i];
									transferSquare(players[], squaresOwned[i]);
									found=true;
									break;
								}
							}
							if (!found){
								cout << "Other player don't have the propety" << endl;	
							}
						}
						else{
							cout << "Trade rejected" << endl;
						}
					}
				}
				break;
			}
		}
	}	
}
