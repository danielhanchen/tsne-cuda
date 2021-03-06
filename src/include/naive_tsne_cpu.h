/**
 * @brief Naive implementation of T-SNE O(n^2) on CPU
 * 
 * @file naive_tsne_cpu.h
 * @author Forrest Huang
 * @date 2018-04-11
 */

#ifndef NAIVE_TSNE_CPU_H
#define NAIVE_TSNE_CPU_H

#include "common.h"
#include "util/cuda_utils.h"
#include "util/math_utils.h"
#include "util/matrix_broadcast_utils.h"
#include "util/reduce_utils.h"
#include "util/distance_utils.h"
#include "util/random_utils.h"


std::vector<float> squared_pairwise_dist(std::vector<float> &points, const unsigned int N, const unsigned int NDIMS);

std::vector<float> sigmas_search_cpu(std::vector<float> &points,  
                             const unsigned int N, 
                             const unsigned int NDIMS,
                             float target_perplexity);

bool perplexity_equal(const float delta, float perplexity, float target_perplexity);

bool compare_perplexity(std::vector<float>& pij, 
             float& lo, 
             float& mid, 
             float& high, 
             const unsigned int i, 
             const unsigned int N, 
             const float delta, 
             const float target_perplexity);

float get_perplexity(std::vector<float> & pij, const unsigned int i, unsigned int N);

void recompute_pij_row_cpu(std::vector<float> &points, 
                             std::vector<float> &pij, 
                             float sigma,
                             float i, 
                             const unsigned int N, 
                             const unsigned int NDIMS);

std::vector<float> compute_pij_cpu(std::vector<float> &points, 
                             std::vector<float> &sigma, 
                             const unsigned int N, 
                             const unsigned int NDIMS);

std::vector<float> compute_qij_cpu(std::vector<float>& ys, const unsigned int N, const unsigned int PROJDIMS);

float kl_div(float pij, float qij);

float compute_gradients_cpu(std::vector<float> &forces,
                      std::vector<float> &dist, 
                        std::vector<float> &ys, 
                        std::vector<float> &pij, 
                        std::vector<float> &qij, 
                        const unsigned int N,
                        float eta);

std::vector<float> naive_tsne_cpu(std::vector<float> &points, 
                              const unsigned int N, 
                              const unsigned int NDIMS);


/*
std::vector<float> compute_qij_cpu(std::vector<float> &ys,
                                   const unsigned int N,
                                   const unsigned int PROJDIM);

float compute_gradients_cpu(std::vector<float> &forces,
                        std::vector<float> &dist, 
                        std::vector<float> &ys, 
                        std::vector<float> &pij, 
                        std::vector<float> &qij, 
                        const unsigned int N,
                        float eta);

std::vector<float> naive_tsne_cpu(std::vector<float> &points, 
                              const unsigned int N, 
                              const unsigned int NDIMS);
*/
#endif
