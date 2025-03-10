#include "LogisticRegression.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <cmath>

LogisticRegression::LogisticRegression() {
    std::ifstream file("logistic_model.txt");
    if (!file.is_open()) {
        std::cerr << "Error: Could not open logistic_model.txt" << std::endl;
        return;
    }

    std::string line;

    // Read intercept
    if (std::getline(file, line)) {
        intercept = std::stod(line);
    }

    // Read coefficients
    if (std::getline(file, line)) {
        std::stringstream ss(line);
        std::string value;
        while (std::getline(ss, value, ',')) {
            coefficients.push_back(std::stod(value));
        }
    }

    file.close();
}

// Sigmoid function for logistic regression
double sigmoid(double x) {
    return 1.0 / (1.0 + std::exp(-x));
}

// Predict probability (between 0 and 1)
double LogisticRegression::predict_proba(const std::vector<double>& features) const {
    if (features.size() != coefficients.size()) {
        std::cerr << "Error: Feature size mismatch" << std::endl;
        return -1.0;
    }

    double linear_sum = intercept;
    for (size_t i = 0; i < features.size(); ++i) {
        linear_sum += features[i] * coefficients[i];
    }

    return sigmoid(linear_sum);
}

// Predict binary outcome (0 or 1)
bool LogisticRegression::predict(const std::vector<double>& features) const {
    return predict_proba(features) >= 0.5;
}
