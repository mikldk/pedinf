// Generated by using Rcpp::compileAttributes() -> do not edit by hand
// Generator token: 10BE3573-1514-4C36-9D1C-5A225CD40393

#include "pedinf_types.hpp"
#include <Rcpp.h>

using namespace Rcpp;

// wipe_pedigrees
void wipe_pedigrees(Rcpp::XPtr< std::vector<Pedigree*> > pedigrees);
RcppExport SEXP _pedinf_wipe_pedigrees(SEXP pedigreesSEXP) {
BEGIN_RCPP
    Rcpp::RNGScope rcpp_rngScope_gen;
    Rcpp::traits::input_parameter< Rcpp::XPtr< std::vector<Pedigree*> > >::type pedigrees(pedigreesSEXP);
    wipe_pedigrees(pedigrees);
    return R_NilValue;
END_RCPP
}
// build_pedigrees_recursive
Rcpp::XPtr< std::vector<Pedigree*> > build_pedigrees_recursive(Rcpp::XPtr<Population> population, bool progress);
RcppExport SEXP _pedinf_build_pedigrees_recursive(SEXP populationSEXP, SEXP progressSEXP) {
BEGIN_RCPP
    Rcpp::RObject rcpp_result_gen;
    Rcpp::RNGScope rcpp_rngScope_gen;
    Rcpp::traits::input_parameter< Rcpp::XPtr<Population> >::type population(populationSEXP);
    Rcpp::traits::input_parameter< bool >::type progress(progressSEXP);
    rcpp_result_gen = Rcpp::wrap(build_pedigrees_recursive(population, progress));
    return rcpp_result_gen;
END_RCPP
}
// build_pedigrees_iterative
Rcpp::XPtr< std::vector<Pedigree*> > build_pedigrees_iterative(Rcpp::XPtr<Population> population, bool progress);
RcppExport SEXP _pedinf_build_pedigrees_iterative(SEXP populationSEXP, SEXP progressSEXP) {
BEGIN_RCPP
    Rcpp::RObject rcpp_result_gen;
    Rcpp::RNGScope rcpp_rngScope_gen;
    Rcpp::traits::input_parameter< Rcpp::XPtr<Population> >::type population(populationSEXP);
    Rcpp::traits::input_parameter< bool >::type progress(progressSEXP);
    rcpp_result_gen = Rcpp::wrap(build_pedigrees_iterative(population, progress));
    return rcpp_result_gen;
END_RCPP
}
// build_maternal_pedigrees_recursive
Rcpp::XPtr< std::vector<Pedigree*> > build_maternal_pedigrees_recursive(Rcpp::XPtr<Population> population, bool progress);
RcppExport SEXP _pedinf_build_maternal_pedigrees_recursive(SEXP populationSEXP, SEXP progressSEXP) {
BEGIN_RCPP
    Rcpp::RObject rcpp_result_gen;
    Rcpp::RNGScope rcpp_rngScope_gen;
    Rcpp::traits::input_parameter< Rcpp::XPtr<Population> >::type population(populationSEXP);
    Rcpp::traits::input_parameter< bool >::type progress(progressSEXP);
    rcpp_result_gen = Rcpp::wrap(build_maternal_pedigrees_recursive(population, progress));
    return rcpp_result_gen;
END_RCPP
}
// wipe_population
void wipe_population(Rcpp::XPtr<Population> population);
RcppExport SEXP _pedinf_wipe_population(SEXP populationSEXP) {
BEGIN_RCPP
    Rcpp::RNGScope rcpp_rngScope_gen;
    Rcpp::traits::input_parameter< Rcpp::XPtr<Population> >::type population(populationSEXP);
    wipe_population(population);
    return R_NilValue;
END_RCPP
}
// load_individuals
Rcpp::XPtr<Population> load_individuals(IntegerVector pid, LogicalVector is_male, IntegerVector pid_mom, IntegerVector pid_dad, bool progress, bool error_on_pid_not_found);
RcppExport SEXP _pedinf_load_individuals(SEXP pidSEXP, SEXP is_maleSEXP, SEXP pid_momSEXP, SEXP pid_dadSEXP, SEXP progressSEXP, SEXP error_on_pid_not_foundSEXP) {
BEGIN_RCPP
    Rcpp::RObject rcpp_result_gen;
    Rcpp::RNGScope rcpp_rngScope_gen;
    Rcpp::traits::input_parameter< IntegerVector >::type pid(pidSEXP);
    Rcpp::traits::input_parameter< LogicalVector >::type is_male(is_maleSEXP);
    Rcpp::traits::input_parameter< IntegerVector >::type pid_mom(pid_momSEXP);
    Rcpp::traits::input_parameter< IntegerVector >::type pid_dad(pid_dadSEXP);
    Rcpp::traits::input_parameter< bool >::type progress(progressSEXP);
    Rcpp::traits::input_parameter< bool >::type error_on_pid_not_found(error_on_pid_not_foundSEXP);
    rcpp_result_gen = Rcpp::wrap(load_individuals(pid, is_male, pid_mom, pid_dad, progress, error_on_pid_not_found));
    return rcpp_result_gen;
END_RCPP
}
// pedinf_test
void pedinf_test();
RcppExport SEXP _pedinf_pedinf_test() {
BEGIN_RCPP
    Rcpp::RNGScope rcpp_rngScope_gen;
    pedinf_test();
    return R_NilValue;
END_RCPP
}
// pop_size
int pop_size(Rcpp::XPtr<Population> population);
RcppExport SEXP _pedinf_pop_size(SEXP populationSEXP) {
BEGIN_RCPP
    Rcpp::RObject rcpp_result_gen;
    Rcpp::RNGScope rcpp_rngScope_gen;
    Rcpp::traits::input_parameter< Rcpp::XPtr<Population> >::type population(populationSEXP);
    rcpp_result_gen = Rcpp::wrap(pop_size(population));
    return rcpp_result_gen;
END_RCPP
}
// pedigrees_count
int pedigrees_count(Rcpp::XPtr< std::vector<Pedigree*> > pedigrees);
RcppExport SEXP _pedinf_pedigrees_count(SEXP pedigreesSEXP) {
BEGIN_RCPP
    Rcpp::RObject rcpp_result_gen;
    Rcpp::RNGScope rcpp_rngScope_gen;
    Rcpp::traits::input_parameter< Rcpp::XPtr< std::vector<Pedigree*> > >::type pedigrees(pedigreesSEXP);
    rcpp_result_gen = Rcpp::wrap(pedigrees_count(pedigrees));
    return rcpp_result_gen;
END_RCPP
}
// pedigree_size
int pedigree_size(Rcpp::XPtr<Pedigree> ped);
RcppExport SEXP _pedinf_pedigree_size(SEXP pedSEXP) {
BEGIN_RCPP
    Rcpp::RObject rcpp_result_gen;
    Rcpp::RNGScope rcpp_rngScope_gen;
    Rcpp::traits::input_parameter< Rcpp::XPtr<Pedigree> >::type ped(pedSEXP);
    rcpp_result_gen = Rcpp::wrap(pedigree_size(ped));
    return rcpp_result_gen;
END_RCPP
}
// pedigrees_table
std::unordered_map<int, int> pedigrees_table(Rcpp::XPtr< std::vector<Pedigree*> > pedigrees);
RcppExport SEXP _pedinf_pedigrees_table(SEXP pedigreesSEXP) {
BEGIN_RCPP
    Rcpp::RObject rcpp_result_gen;
    Rcpp::RNGScope rcpp_rngScope_gen;
    Rcpp::traits::input_parameter< Rcpp::XPtr< std::vector<Pedigree*> > >::type pedigrees(pedigreesSEXP);
    rcpp_result_gen = Rcpp::wrap(pedigrees_table(pedigrees));
    return rcpp_result_gen;
END_RCPP
}
// get_pedigree
Rcpp::XPtr<Pedigree> get_pedigree(Rcpp::XPtr< std::vector<Pedigree*> > pedigrees, int index);
RcppExport SEXP _pedinf_get_pedigree(SEXP pedigreesSEXP, SEXP indexSEXP) {
BEGIN_RCPP
    Rcpp::RObject rcpp_result_gen;
    Rcpp::RNGScope rcpp_rngScope_gen;
    Rcpp::traits::input_parameter< Rcpp::XPtr< std::vector<Pedigree*> > >::type pedigrees(pedigreesSEXP);
    Rcpp::traits::input_parameter< int >::type index(indexSEXP);
    rcpp_result_gen = Rcpp::wrap(get_pedigree(pedigrees, index));
    return rcpp_result_gen;
END_RCPP
}
// get_individual
Rcpp::XPtr<Individual> get_individual(Rcpp::XPtr<Population> population, int pid);
RcppExport SEXP _pedinf_get_individual(SEXP populationSEXP, SEXP pidSEXP) {
BEGIN_RCPP
    Rcpp::RObject rcpp_result_gen;
    Rcpp::RNGScope rcpp_rngScope_gen;
    Rcpp::traits::input_parameter< Rcpp::XPtr<Population> >::type population(populationSEXP);
    Rcpp::traits::input_parameter< int >::type pid(pidSEXP);
    rcpp_result_gen = Rcpp::wrap(get_individual(population, pid));
    return rcpp_result_gen;
END_RCPP
}
// print_individual
void print_individual(Rcpp::XPtr<Individual> individual);
RcppExport SEXP _pedinf_print_individual(SEXP individualSEXP) {
BEGIN_RCPP
    Rcpp::RNGScope rcpp_rngScope_gen;
    Rcpp::traits::input_parameter< Rcpp::XPtr<Individual> >::type individual(individualSEXP);
    print_individual(individual);
    return R_NilValue;
END_RCPP
}
// get_children_count
int get_children_count(Rcpp::XPtr<Individual> individual);
RcppExport SEXP _pedinf_get_children_count(SEXP individualSEXP) {
BEGIN_RCPP
    Rcpp::RObject rcpp_result_gen;
    Rcpp::RNGScope rcpp_rngScope_gen;
    Rcpp::traits::input_parameter< Rcpp::XPtr<Individual> >::type individual(individualSEXP);
    rcpp_result_gen = Rcpp::wrap(get_children_count(individual));
    return rcpp_result_gen;
END_RCPP
}
// print_pedigree
void print_pedigree(Rcpp::XPtr<Pedigree> ped);
RcppExport SEXP _pedinf_print_pedigree(SEXP pedSEXP) {
BEGIN_RCPP
    Rcpp::RNGScope rcpp_rngScope_gen;
    Rcpp::traits::input_parameter< Rcpp::XPtr<Pedigree> >::type ped(pedSEXP);
    print_pedigree(ped);
    return R_NilValue;
END_RCPP
}
// get_pids_in_pedigree
IntegerVector get_pids_in_pedigree(Rcpp::XPtr<Pedigree> ped);
RcppExport SEXP _pedinf_get_pids_in_pedigree(SEXP pedSEXP) {
BEGIN_RCPP
    Rcpp::RObject rcpp_result_gen;
    Rcpp::RNGScope rcpp_rngScope_gen;
    Rcpp::traits::input_parameter< Rcpp::XPtr<Pedigree> >::type ped(pedSEXP);
    rcpp_result_gen = Rcpp::wrap(get_pids_in_pedigree(ped));
    return rcpp_result_gen;
END_RCPP
}
// get_pedigree_edgelist
CharacterMatrix get_pedigree_edgelist(Rcpp::XPtr<Pedigree> ped);
RcppExport SEXP _pedinf_get_pedigree_edgelist(SEXP pedSEXP) {
BEGIN_RCPP
    Rcpp::RObject rcpp_result_gen;
    Rcpp::RNGScope rcpp_rngScope_gen;
    Rcpp::traits::input_parameter< Rcpp::XPtr<Pedigree> >::type ped(pedSEXP);
    rcpp_result_gen = Rcpp::wrap(get_pedigree_edgelist(ped));
    return rcpp_result_gen;
END_RCPP
}
// get_pedigree_as_graph
List get_pedigree_as_graph(Rcpp::XPtr<Pedigree> ped);
RcppExport SEXP _pedinf_get_pedigree_as_graph(SEXP pedSEXP) {
BEGIN_RCPP
    Rcpp::RObject rcpp_result_gen;
    Rcpp::RNGScope rcpp_rngScope_gen;
    Rcpp::traits::input_parameter< Rcpp::XPtr<Pedigree> >::type ped(pedSEXP);
    rcpp_result_gen = Rcpp::wrap(get_pedigree_as_graph(ped));
    return rcpp_result_gen;
END_RCPP
}
// get_pedigree_from_individual
Rcpp::XPtr<Pedigree> get_pedigree_from_individual(Rcpp::XPtr<Individual> individual);
RcppExport SEXP _pedinf_get_pedigree_from_individual(SEXP individualSEXP) {
BEGIN_RCPP
    Rcpp::RObject rcpp_result_gen;
    Rcpp::RNGScope rcpp_rngScope_gen;
    Rcpp::traits::input_parameter< Rcpp::XPtr<Individual> >::type individual(individualSEXP);
    rcpp_result_gen = Rcpp::wrap(get_pedigree_from_individual(individual));
    return rcpp_result_gen;
END_RCPP
}
// get_pedigree_id_from_pid
IntegerVector get_pedigree_id_from_pid(Rcpp::XPtr<Population> population, IntegerVector pids);
RcppExport SEXP _pedinf_get_pedigree_id_from_pid(SEXP populationSEXP, SEXP pidsSEXP) {
BEGIN_RCPP
    Rcpp::RObject rcpp_result_gen;
    Rcpp::RNGScope rcpp_rngScope_gen;
    Rcpp::traits::input_parameter< Rcpp::XPtr<Population> >::type population(populationSEXP);
    Rcpp::traits::input_parameter< IntegerVector >::type pids(pidsSEXP);
    rcpp_result_gen = Rcpp::wrap(get_pedigree_id_from_pid(population, pids));
    return rcpp_result_gen;
END_RCPP
}
// get_pedigree_size_from_pid
IntegerVector get_pedigree_size_from_pid(Rcpp::XPtr<Population> population, IntegerVector pids);
RcppExport SEXP _pedinf_get_pedigree_size_from_pid(SEXP populationSEXP, SEXP pidsSEXP) {
BEGIN_RCPP
    Rcpp::RObject rcpp_result_gen;
    Rcpp::RNGScope rcpp_rngScope_gen;
    Rcpp::traits::input_parameter< Rcpp::XPtr<Population> >::type population(populationSEXP);
    Rcpp::traits::input_parameter< IntegerVector >::type pids(pidsSEXP);
    rcpp_result_gen = Rcpp::wrap(get_pedigree_size_from_pid(population, pids));
    return rcpp_result_gen;
END_RCPP
}
// get_pedigree_id_from_pedigree
int get_pedigree_id_from_pedigree(Rcpp::XPtr<Pedigree> ped);
RcppExport SEXP _pedinf_get_pedigree_id_from_pedigree(SEXP pedSEXP) {
BEGIN_RCPP
    Rcpp::RObject rcpp_result_gen;
    Rcpp::RNGScope rcpp_rngScope_gen;
    Rcpp::traits::input_parameter< Rcpp::XPtr<Pedigree> >::type ped(pedSEXP);
    rcpp_result_gen = Rcpp::wrap(get_pedigree_id_from_pedigree(ped));
    return rcpp_result_gen;
END_RCPP
}
// number_of_singletons
int number_of_singletons(Rcpp::XPtr<Population> population);
RcppExport SEXP _pedinf_number_of_singletons(SEXP populationSEXP) {
BEGIN_RCPP
    Rcpp::RObject rcpp_result_gen;
    Rcpp::RNGScope rcpp_rngScope_gen;
    Rcpp::traits::input_parameter< Rcpp::XPtr<Population> >::type population(populationSEXP);
    rcpp_result_gen = Rcpp::wrap(number_of_singletons(population));
    return rcpp_result_gen;
END_RCPP
}

static const R_CallMethodDef CallEntries[] = {
    {"_pedinf_wipe_pedigrees", (DL_FUNC) &_pedinf_wipe_pedigrees, 1},
    {"_pedinf_build_pedigrees_recursive", (DL_FUNC) &_pedinf_build_pedigrees_recursive, 2},
    {"_pedinf_build_pedigrees_iterative", (DL_FUNC) &_pedinf_build_pedigrees_iterative, 2},
    {"_pedinf_build_maternal_pedigrees_recursive", (DL_FUNC) &_pedinf_build_maternal_pedigrees_recursive, 2},
    {"_pedinf_wipe_population", (DL_FUNC) &_pedinf_wipe_population, 1},
    {"_pedinf_load_individuals", (DL_FUNC) &_pedinf_load_individuals, 6},
    {"_pedinf_pedinf_test", (DL_FUNC) &_pedinf_pedinf_test, 0},
    {"_pedinf_pop_size", (DL_FUNC) &_pedinf_pop_size, 1},
    {"_pedinf_pedigrees_count", (DL_FUNC) &_pedinf_pedigrees_count, 1},
    {"_pedinf_pedigree_size", (DL_FUNC) &_pedinf_pedigree_size, 1},
    {"_pedinf_pedigrees_table", (DL_FUNC) &_pedinf_pedigrees_table, 1},
    {"_pedinf_get_pedigree", (DL_FUNC) &_pedinf_get_pedigree, 2},
    {"_pedinf_get_individual", (DL_FUNC) &_pedinf_get_individual, 2},
    {"_pedinf_print_individual", (DL_FUNC) &_pedinf_print_individual, 1},
    {"_pedinf_get_children_count", (DL_FUNC) &_pedinf_get_children_count, 1},
    {"_pedinf_print_pedigree", (DL_FUNC) &_pedinf_print_pedigree, 1},
    {"_pedinf_get_pids_in_pedigree", (DL_FUNC) &_pedinf_get_pids_in_pedigree, 1},
    {"_pedinf_get_pedigree_edgelist", (DL_FUNC) &_pedinf_get_pedigree_edgelist, 1},
    {"_pedinf_get_pedigree_as_graph", (DL_FUNC) &_pedinf_get_pedigree_as_graph, 1},
    {"_pedinf_get_pedigree_from_individual", (DL_FUNC) &_pedinf_get_pedigree_from_individual, 1},
    {"_pedinf_get_pedigree_id_from_pid", (DL_FUNC) &_pedinf_get_pedigree_id_from_pid, 2},
    {"_pedinf_get_pedigree_size_from_pid", (DL_FUNC) &_pedinf_get_pedigree_size_from_pid, 2},
    {"_pedinf_get_pedigree_id_from_pedigree", (DL_FUNC) &_pedinf_get_pedigree_id_from_pedigree, 1},
    {"_pedinf_number_of_singletons", (DL_FUNC) &_pedinf_number_of_singletons, 1},
    {NULL, NULL, 0}
};

RcppExport void R_init_pedinf(DllInfo *dll) {
    R_registerRoutines(dll, NULL, CallEntries, NULL, NULL);
    R_useDynamicSymbols(dll, FALSE);
}
