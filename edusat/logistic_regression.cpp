#include "LogisticRegression.h"
#include "edusat_pripro.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <cmath>
#include "logistic_regression.h"

LogisticRegression::LogisticRegression() {
    std::ifstream file("logistic_model.txt");
    if (!file.is_open()) {
        std::cerr << "Error: Could not open logistic_model.txt" << std::endl;
        return;
    }
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

    // Read threshold (last line)
    if (std::getline(file, line)) {
        threshold = std::stod(line);
    }

    file.close();
}
vector<double> LogisticRegression::Clause_To_features(const clause_t c) const
{
    return vector<double>();
}
// Sigmoid function for logistic regression
double sigmoid(double x) {
    return 1.0 / (1.0 + std::exp(-x));
}

vector<double> Clause_To_features(const clause_t c) {
    int num_neg = 0;
    int num_pos = 0;
    std::vector<double>& features;
    for (vector<int>::iterator it = c.begin(); it != c.end(); ++it) {
        if (l2rl(*it) > 0)
            num_pos++;
        else num_neg++;
    }
    double ratio = num_neg > 0 ? num_pos / num_neg : num_pos;
    features.push_back(ratio);
    features.push_back(num_pos);
    features.push_back(num_neg);
    return features;
}

// Predict probability (between 0 and 1)
double LogisticRegression::predict_proba(const Clause& c) const {
    const std::vector<double>& features = Clause_To_features(c.cl())
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
bool LogisticRegression::predict(const Clause& c) const {
    const std::vector<double>& features=Clause_To_features(c.cl())
    return predict_proba(features) >= threshold;
}
