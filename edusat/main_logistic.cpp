#include "LogisticRegression.h"
#include <iostream>

int main() {
    LogisticRegression model;

    // Example input features: ratio, pos_count, neg_count
    std::vector<double> example_features = { 2.5, 10, 4 };

    double probability = model.predict_proba(example_features);
    bool prediction = model.predict(example_features);

    std::cout << "Predicted probability: " << probability << std::endl;
    std::cout << "Binary classification: " << (prediction ? "1 (True)" : "0 (False)") << std::endl;

    return 0;
}
