/** 
 * @class FormulationCompact
*/

#ifndef FormulationCompact_H
#define FormulationCompact_H


//** Includes

//* Standart
#include <vector>
#include <iostream>
#include <string>
#include <fstream>
#include <sstream>


//* SCIP
#include <scip/scipdefplugins.h>
#include <scip/scip.h>


//* User

// general
#include "DataClasses/InstanceUCP.h"

// Decomposition
#include "OtherResolution/FormulationCompact.h"


class FormulationCompact
{

    public : 

        /* constructor */
        FormulationCompact(InstanceUCP *instance, SCIP *scip);

        /* create the variables, add them to scip and store them */
        SCIP_RETCODE create_variables();

        /* create the constraints, add them to scip problem and store them */
        SCIP_RETCODE create_constraints();

        
        /* gets */

        SCIP* get_scip_pointer();

        std::vector< std::vector< SCIP_VAR* >> get_variable_u();
        std::vector< std::vector< SCIP_VAR* >> get_variable_x();
        std::vector< std::vector< SCIP_VAR* >> get_variable_p();

        std::vector< std::vector< SCIP_CONS* >> m_constraint_min_up_time;



    private:

        SCIP *p_scip;
        InstanceUCP *p_ucp_instance;

        std::vector< std::vector< SCIP_VAR* >> m_variable_u;
        std::vector< std::vector< SCIP_VAR* >> m_variable_x;
        std::vector< std::vector< SCIP_VAR* >> m_variable_p;

        std::vector< SCIP_CONS* > m_constraint_demand;
        std::vector< std::vector< SCIP_CONS* >> m_constraint_production;
        // std::vector< std::vector< SCIP_CONS* >> m_constraint_min_up_time;
        std::vector< std::vector< SCIP_CONS* >> m_constraint_min_down_time;
        std::vector< std::vector< SCIP_CONS* >> m_constraint_startup;
     

};

#endif