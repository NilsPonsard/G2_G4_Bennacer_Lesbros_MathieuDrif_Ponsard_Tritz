#include "scoresort.h"
#include <algorithm>

using namespace std;

//http://www.cplusplus.com/reference/algorithm/sort/

/*!
 * \brief Compares scores contained in the pairs of name - score
 *          is used by the sort algorithm in the algorithm library
 * \param a : first pair containing the score
 * \param b : second pair containing the score
 * \return returns :
 *          <ul>
 *          <li> true if a>b</li>
 *          <li> false if a<b</li>
 *         </ul>
 */
bool compPairs(const pair<string, unsigned> &a, const pair<string, unsigned> &b)
{
    return (a.second > b.second);
}

/*!
 *
 * \brief Sorts all the scores contained in pairs of name - score
 * \param scores : vector containing pairs of name - score
 * 
 */

void scoreSort(vector<pair<string, unsigned>> &scores)
{
    sort(scores.begin(), scores.end(), compPairs);
}

/*!
 * \brief Inserts a new pair of name - score in the right position in a vector
 * \param scores : vector containing pairs of name - score, in which the new score will be added
 * \param nom : the name corresponding to the score which will be added
 * \param score : the score which will be added to the vector
 * \param popBack : if true, removes the last elements after insertion
 */

void insertScore(vector<pair<string, unsigned>> & scores, const string &nom, const unsigned & score, const bool & popBack)
{
    scores.resize(scores.size() + 1);

    unsigned i(scores.size() - 1);
    for( ; i > 0 && scores[i - 1].second < score; --i)
        scores[i] = scores[i - 1];

    scores[i] = make_pair(nom, score);

    if(popBack)
        scores.pop_back();
}
