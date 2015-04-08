#include "zero_matrix.hpp"

int ZeroMatrixTask::TASKID;

ZeroMatrixTask::ZeroMatrixTask(Domain domain,
			       TaskArgument global_arg,
			       ArgumentMap arg_map,
			       Predicate pred,
			       bool must,
			       MapperID id,
			       MappingTagID tag)
  
  : IndexLauncher(TASKID, domain, global_arg,
		  arg_map, pred, must, id, tag) {}

void ZeroMatrixTask::register_tasks(void)
{
  TASKID = HighLevelRuntime::register_legion_task
    <ZeroMatrixTask::cpu_task>(AUTO_GENERATE_ID,
			       Processor::LOC_PROC, 
			       false,
			       true,
			       AUTO_GENERATE_ID,
			       TaskConfigOptions(true/*leaf*/),
			       "Zero_Matrix");

#ifdef SHOW_REGISTER_TASKS
  printf("Register task %d : Zero_Matrix\n", TASKID);
#endif
}

void ZeroMatrixTask::cpu_task(const Task *task,
			      const std::vector<PhysicalRegion> &regions,
			      Context ctx, HighLevelRuntime *runtime) {
}



