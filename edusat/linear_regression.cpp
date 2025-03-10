#include "LinearRegressionModel.h"

// Constructor initializes intercept to 0
LinearRegressionModel::LinearRegressionModel() : intercept(0.0) {}

// Function to load the linear regression model from a file
bool LinearRegressionModel::loadModel(const std::string& filename) {
    std::ifstream file(filename);
    if (!file.is_open()) {
        std::cerr << "Error: Unable to open model file: " << filename << std::endl;
        return false;
    }

    file >> intercept; // Read the intercept
    double coef;
    coefficients.clear(); // Clear any previous coefficients

    while (file >> coef) {
        coefficients.push_back(coef);
    }

    file.close();
    std::cout << "Model loaded successfully. Intercept: " << intercept << ", Coefficients: ";
    for (const auto& c : coefficients) {
        std::cout << c << " ";
    }
    std::cout << std::endl;

    return true;
}

// Function to make predictions using the loaded model
double LinearRegressionModel::predict(const std::vector<double>& features) const {
    if (features.size() != coefficients.size()) {
        std::cerr << "Error: Feature vector size does not match the number of coefficients." << std::endl;
        return 0.0;
    }

    double prediction = intercept;
    for (size_t i = 0; i < features.size(); ++i) {
        prediction += features[i] * coefficients[i];
    }

    return prediction;
}

// Function to write a vector to a CSV file
void LinearRegressionModel::writeVectorToCSV(const std::vector<int>& indices, const std::vector<double>& data, const std::string& filename) const {
    if (indices.size() != data.size()) {
        std::cerr << "Error: Indices and data vectors must have the same size." << std::endl;
        return;
    }

    std::ofstream file(filename);
    if (!file.is_open()) {
        std::cerr << "Error opening file: " << filename << std::endl;
        return;
    }

    file << "Index,Value\n";
    for (size_t i = 0; i < data.size(); ++i) {
        file << indices[i] << "," << data[i] << "\n";
    }

    file.close();
    std::cout << "Data written to " << filename << std::endl;
}
