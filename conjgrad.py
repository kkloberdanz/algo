# based on
# https://en.wikipedia.org/wiki/Conjugate_gradient_method#Example_code_in_MATLAB_/_GNU_Octave
#
# To compare against direct method:
# np.linalg.inv(X.T.dot(X)).dot(X.T).dot(y) - ols(X, y)


def conjgrad(A, b, epsilon=0.00001):
    N, _ = A.shape
    x = np.random.rand(N)
    r = b - A.dot(x)
    p = r.copy()
    residual_old = r.T.dot(r)

    for i in range(N * N):
        Ap = A.dot(p)
        alpha = residual_old / (p.T.dot(Ap))
        x = x + alpha * p
        r = r - alpha * Ap
        residual_new = r.T.dot(r)
        if np.sqrt(residual_new) < epsilon:
            print(f"solved in {i} iterations")
            return x
        else:
            p = r + (residual_new / residual_old) * p
            residual_old = residual_new
    print(f"did not converg after {N} iterations")
    return x


def ols(X, y):
    # B = np.linalg.inv(X.T.dot(X)).dot(X.T).dot(y)
    # Ax = b
    # X.T X B = X.T y
    # A = X.T X
    # b = X.T y
    return conjgrad(X.T.dot(X), X.T.dot(y))
