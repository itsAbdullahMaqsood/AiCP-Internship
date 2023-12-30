
#include <iostream>
    using namespace std;

    const int NUM_JOURNEYS = 4;
    const double GROUP_DISCOUNT_RATE = 0.1;

    struct JourneyData {
        int availableTickets;
        int passengers;
        double money;
    };

    void purchaseTickets(JourneyData & journey, int numTickets, double fare) {
        if (journey.availableTickets >= numTickets) {
            journey.availableTickets -= numTickets;
            journey.passengers += numTickets;
            journey.money += numTickets * fare * (1.0 - (numTickets > 1 ? GROUP_DISCOUNT_RATE : 0.0));
            cout << "Tickets purchased successfully!" << endl;
        }
        else {
            cout << "Not enough available tickets." << endl;
        }
    }

    int main() {
        JourneyData upJourneys[NUM_JOURNEYS] = { {100}, {100}, {100}, {100} };
        JourneyData downJourneys[NUM_JOURNEYS] = { {100}, {100}, {100}, {100} };

        cout << "\t\t\t=== Start of the Day ===" << endl;

        int journeyNum, numTickets;
        double fare;

        cout << "\nPurchase Tickets:" << endl;
        cout << "Journey (1-" << NUM_JOURNEYS << "): ";
        cin >> journeyNum;

        if (journeyNum >= 1 && journeyNum <= NUM_JOURNEYS) {
            JourneyData& selectedJourney = upJourneys[journeyNum - 1];
            cout << "Number of Tickets: ";
            cin >> numTickets;

            cout << "Fare per Ticket: Rs";
            cin >> fare;

            purchaseTickets(selectedJourney, numTickets, fare);
        }
        else {
            cout << "Invalid journey number." << endl;
        }

        return 0;
    }