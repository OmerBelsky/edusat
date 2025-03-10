#ifndef LINEAR_REGRESSION_MODEL_H
#define LINEAR_REGRESSION_MODEL_H

#include <iostream>
#include <vector>
#include <fstream>
#include <string>

class LinearRegressionModel {
private:
    double intercept;
    std::vector<double> coefficients;

public:
    LinearRegressionModel();
    bool loadModel(const std::string& filename);
    double predict(const std::vector<double>& features) const;
    void writeVectorToCSV(const std::vector<int>& indices, const std::vector<double>& data, const std::string& filename = "cnf_data.csv") const;
};

#endif // LINEAR_REGRESSION_MODEL_H
