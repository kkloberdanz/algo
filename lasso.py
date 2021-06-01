import numpy as np
import pandas as pd
from sklearn import linear_model


def fit(X, y, alpha=1.0):
    (n_observations, n_features) = X.shape
    (y_len,) = y.shape

    if n_observations != y_len:
        msg = "y must be the same lengeth as the number of rows in X"
        raise ValueError(msg)

    weights = np.random.randn(n_features) / np.sqrt(n_features)

    # LASSO is convex, so a local minimum is a global minimum
    learning_rate = 0.0001

    tol = 0.0001
    old_mse = None

    for i in range(10000):
        y_pred = X.dot(weights)
        residuals = y - y_pred
        gradient = X.T.dot(residuals) + alpha * np.sign(weights)
        weights += learning_rate * gradient
        if old_mse is None:
            mse = residuals.dot(residuals) / n_observations
            old_mse = mse
        else:
            old_mse = mse
            mse = residuals.dot(residuals) / n_observations
            diff = np.abs(mse - old_mse)
            if diff < tol:
                print(f"converged after {i} iterations")
                return weights, mse
    print(f"failed to converg after {i + 1} iterations")
    return weights, mse


def predict(X, weights):
    return X.dot(weights)


n_observations = 50
n_features = 50

X = (np.random.random((n_observations, n_features)) - 0.5) * 10
w_dash = np.array([1, 0.5, -0.5] + [0] * (n_features - 3))
y = X.dot(w_dash) + np.random.randn(n_observations) * 0.5

weights, mse = fit(X, y)
print("mse =", mse)

y_pred = predict(X, weights)

lasso = linear_model.Lasso(alpha=1.0)
lasso.fit(X, y)
sk_y_pred = lasso.predict(X)

print(sk_y_pred)
print(y_pred - sk_y_pred)

# df = pd.read_csv("asec_csv_repwgt_2020.csv")
# cols = [f"pwwgt{i}" for i in range(161)]
# y = df["PPPOS"]
# X = df[cols].to_numpy()
# weights = fit(X, y)
# print("final weights:", weights)
