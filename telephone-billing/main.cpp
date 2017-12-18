#include <iostream>

#include "telephone_bill.h"
#include "telephone_bill_manager.h"
#include "telephone_bill_options.h"
#include "user.h"
#include "user_manager.h"
#include "user_options.h"

UserManager *user_manager_;
TelephoneBillManager *telephone_bill_manager_;

void initialize(Rate rate) {

	user_manager_ = new UserManager();
	user_manager_->Populate();

	telephone_bill_manager_ = new TelephoneBillManager(rate);
	telephone_bill_manager_->Populate();

}

void shutdown() {

	user_manager_->Persist();
	delete(user_manager_);

	telephone_bill_manager_->Persist();
	delete(telephone_bill_manager_);

}

int main() {

	Rate rate(0, 0, 0, 0);
	initialize(rate);

	bool loop = true;
	while (loop) {

		cout << "Telephone Billing \n";
		cout << "1 -> User \n";
		cout << "2 -> Telephone Bill \n";
		cout << "_ -> Exit \n";

		int option;
		cin >> option;

		switch (option) {
		case 1:
			UserOptions(*telephone_bill_manager_, *user_manager_).Interact();
			break;
		case 2:
			break;
		default:
			loop = false;
			break;
		}

	}

	shutdown();

	return 0;

}