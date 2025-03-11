#ifndef LOGISTIC_REGRESSION_H
#define LOGISTIC_REGRESSION_H

#include <vector>
#include <string>

class LogisticRegression {
private:
    double intercept;
    std::vector<double> coefficients;

public:
    LogisticRegression();  // Constructor to load model
    bool predict(const std::vector<double>& features) const; // Binary prediction
    double predict_proba(const std::vector<double>& features) const; // Probability prediction
};

#endif // LOGISTIC_REGRESSION_H
