#include "jsvm.h"

#include <mda32.h>

bool get_svm_discrim_direction(double& cutoff, QVector<double>& direction, const Mda32& X, const QVector<int>& labels)
{
    int num_points = X.N2();
    int num_dims = X.N1();

    svm_parameter param;
    param.svm_type = C_SVC;
    param.kernel_type = LINEAR;
    param.degree = 0;
    param.gamma = 0.5;
    param.coef0 = 0;
    param.nu = 0;
    param.cache_size = 100;
    param.C = 1;
    param.eps = 1e-6;
    param.p = 0.1;
    param.shrinking = 1;
    param.probability = 0;
    param.nr_weight = 0;
    param.weight_label = NULL;
    param.weight = NULL;

    svm_problem prob;
    prob.l = num_points;
    prob.y = new double[num_points];

    svm_node* x_space = new svm_node[(num_dims + 1) * num_points];
    prob.x = new svm_node* [num_points];

    for (int i = 0; i < num_points; i++) {
        for (int d = 0; d < num_dims; d++) {
            x_space[(num_dims + 1) * i + d].index = d;
            x_space[(num_dims + 1) * i + d].value = X.value(d, i);
        }

        x_space[(num_dims + 1) * i + num_dims].index = -1;
        prob.x[i] = &x_space[(num_dims + 1) * i];

        prob.y[i] = labels[i];
    }

    svm_model* model = svm_train(&prob, &param);

    direction.clear();
    for (int d = 0; d < num_dims; d++)
        direction << 0;
    for (int i = 0; i < model->l; i++) {
        for (int d = 0; d < num_dims; d++) {
            direction[d] += model->sv_coef[0][i] * model->SV[i][d].value;
        }
    }
    cutoff = model->rho[0];

    svm_free_and_destroy_model(&model);
    delete prob.y;

    return true;
}
